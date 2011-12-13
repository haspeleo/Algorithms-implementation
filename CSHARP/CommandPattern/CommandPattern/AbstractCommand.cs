using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CommandPattern {
    
    abstract class AbstractCommand {

        protected Receiver receiver;

        public AbstractCommand(Receiver receiver) {

            this.receiver = receiver; 
        }

        public abstract void Execute(); // { }


       
    }
}
