#include <iostream>
#include <string.h>
#include "runner.h"


char** getArguments(int argc, char** argv)
{
    char** args = new char*[argc];
    for(int i = 1; i < argc; ++i)
    {
        size_t len = strlen(argv[i]);
        args[i - 1] = new char[len + 1];
        strncpy(args[i - 1], argv[i], len);
    }
    // set bound element
    args[argc - 1] = 0;
    return args;
}

void freeArguments(char** args, size_t dim)
{
    for(int i = 1; i < dim; ++i)
    {
        delete[] args[i];
    }
    delete[] args;
}

int main(int argc, char **argv)
{
    char** args = getArguments(argc, argv);
    
    g_type_init ();

    GError *error = NULL;
    DBusGConnection *connection = dbus_g_bus_get(DBUS_BUS_SESSION, &error);
    if(connection == NULL)
    {
        std::cerr << "Failed to open connection to bus: " <<
                    error->message << std::endl;
        g_error_free(error);
        return 1;
    }


    DBusGProxy *proxy = dbus_g_proxy_new_for_name(connection,
                                        "com.CommandServer.Runner",
                                        "/com/CommandServer/Runner",
                                        "com.CommandServer.Runner");

    error = NULL;
    GValueArray* out;
    if (!com_CommandServer_Runner_sample_command(proxy, (const char**)args, &out, &error))
    {
        // if exception thrown
        if (error->domain == DBUS_GERROR && error->code == DBUS_GERROR_REMOTE_EXCEPTION)
        {
            std::cerr << "Caught remote method exception " <<
                    dbus_g_error_get_name (error) << ":" <<
                    error->message << std::endl;
        }
        else
        {
            std::cerr << "Error: " << error->message << std::endl;
        }
        g_error_free(error);
        return 1;
    }

    GValue* returnCode = g_value_array_get_nth(out, 0);
    GValue* msgString = g_value_array_get_nth(out, 1);
    
    std::cout << "return code: " << g_value_get_int(returnCode) << std::endl;
    std::cout << "message: " << g_value_get_string(msgString) << std::endl;

    g_object_unref (proxy);
    freeArguments(args, argc);

    return 0;
}
