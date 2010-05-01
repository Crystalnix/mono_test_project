using System;
using System.Runtime.InteropServices;
using NDesk.DBus;
using org.freedesktop.DBus;

namespace command_server
{
    [StructLayout(LayoutKind.Sequential)]
    public struct ResponseObject
    {
        public int returnCode;
        public string message;
        
        public ResponseObject(int returnCode, string message)
        {
            this.returnCode = returnCode;
            this.message = message;
        }
    }
    
    [Interface ("com.CommandServer.Runner")]
    public interface IRunner
    {
        ResponseObject SampleCommand(string[] args);
        
    }
    
    public class SampleRunnerImplementation : IRunner
    {
        public ResponseObject SampleCommand(string[] args)
        {
            string msg = "";
            Array.ForEach(args, delegate (string arg) { msg += arg + " "; });
            // return number of argments and concatenated arguments string
            Console.WriteLine("Arguments from client: {0}", msg);
            return new ResponseObject(args.Length, msg);
        }
    }
    
    class MainClass
    {
        public static int Main (string[] args)
        {
            Console.WriteLine ("Starting DBus service");
            
            Bus bus = Bus.Session;
            IRunner runner;
            ObjectPath objPath = new ObjectPath("/com/CommandServer/Runner");
            string busName = "com.CommandServer.Runner";
            
            if(bus.RequestName(busName) == RequestNameReply.PrimaryOwner) 
            {
                runner = new SampleRunnerImplementation();
                bus.Register(objPath, runner);
            }
            else
            {
                Console.WriteLine("server instance already running");
                return 1;
            }
                        
            //run the main loop
            while (true)
                bus.Iterate ();            
        }
    }
}

