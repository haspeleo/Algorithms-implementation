using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FactoryPattern {
   
    abstract class Creator {

        public abstract Product FactoryMethod();
    }
}
