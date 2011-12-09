using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CommandPattern {


    class Invoker {


        private AbstractCommand command;

        public void SetCommand(AbstractCommand command) {
            
            this.command = command;
        }

        public void ExecuteCommand() {
           
            command.Execute();
        }    


    }
}
