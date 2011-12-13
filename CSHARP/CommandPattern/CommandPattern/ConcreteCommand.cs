using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;



namespace CommandPattern {
    
    class ConcreteCommand : AbstractCommand {

        private Receiver receiver;
        

        public ConcreteCommand(Receiver receiver) : base (receiver) {}

        public override void Execute() {

            receiver.Action();
        }

    }
}
