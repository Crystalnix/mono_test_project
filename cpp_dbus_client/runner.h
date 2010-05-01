/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef _DBUS_GLIB_ASYNC_DATA_FREE
#define _DBUS_GLIB_ASYNC_DATA_FREE
static
#ifdef G_HAVE_INLINE
inline
#endif
void
_dbus_glib_async_data_free (gpointer stuff)
{
	g_slice_free (DBusGAsyncData, stuff);
}
#endif

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_DBus_Introspectable
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_DBus_Introspectable

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_Introspectable_introspect (DBusGProxy *proxy, char ** OUT_data, GError **error)

{
  return dbus_g_proxy_call (proxy, "Introspect", error, G_TYPE_INVALID, G_TYPE_STRING, OUT_data, G_TYPE_INVALID);
}

typedef void (*org_freedesktop_DBus_Introspectable_introspect_reply) (DBusGProxy *proxy, char * OUT_data, GError *error, gpointer userdata);

static void
org_freedesktop_DBus_Introspectable_introspect_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_data;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_data, G_TYPE_INVALID);
  (*(org_freedesktop_DBus_Introspectable_introspect_reply)data->cb) (proxy, OUT_data, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_Introspectable_introspect_async (DBusGProxy *proxy, org_freedesktop_DBus_Introspectable_introspect_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_slice_new (DBusGAsyncData);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Introspect", org_freedesktop_DBus_Introspectable_introspect_async_callback, stuff, _dbus_glib_async_data_free, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_DBus_Introspectable */

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_com_CommandServer_Runner
#define DBUS_GLIB_CLIENT_WRAPPERS_com_CommandServer_Runner

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
com_CommandServer_Runner_sample_command (DBusGProxy *proxy, const char ** IN_args, GValueArray** OUT_ret, GError **error)

{
  return dbus_g_proxy_call (proxy, "SampleCommand", error, G_TYPE_STRV, IN_args, G_TYPE_INVALID, dbus_g_type_get_struct ("GValueArray", G_TYPE_INT, G_TYPE_STRING, G_TYPE_INVALID), OUT_ret, G_TYPE_INVALID);
}

typedef void (*com_CommandServer_Runner_sample_command_reply) (DBusGProxy *proxy, GValueArray *OUT_ret, GError *error, gpointer userdata);

static void
com_CommandServer_Runner_sample_command_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GValueArray* OUT_ret;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_struct ("GValueArray", G_TYPE_INT, G_TYPE_STRING, G_TYPE_INVALID), &OUT_ret, G_TYPE_INVALID);
  (*(com_CommandServer_Runner_sample_command_reply)data->cb) (proxy, OUT_ret, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
com_CommandServer_Runner_sample_command_async (DBusGProxy *proxy, const char ** IN_args, com_CommandServer_Runner_sample_command_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_slice_new (DBusGAsyncData);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "SampleCommand", com_CommandServer_Runner_sample_command_async_callback, stuff, _dbus_glib_async_data_free, G_TYPE_STRV, IN_args, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_com_CommandServer_Runner */

G_END_DECLS