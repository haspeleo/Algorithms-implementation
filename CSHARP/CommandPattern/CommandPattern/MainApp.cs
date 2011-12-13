using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CommandPattern {
   
    class MainApp {
        
        static void Main(string[] args) {

            
            // create receiver, command and invoker
            Receiver receiver = new Receiver();
            AbstractCommand command = new ConcreteCommand(receiver);
            Invoker invoker = new Invoker();

            // set and execute command
            invoker.SetCommand(command);
            invoker.ExecuteCommand();

            
            //wait for user
            Console.Read();

        }
    }
}
