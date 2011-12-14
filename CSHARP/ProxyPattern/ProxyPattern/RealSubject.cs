using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProxyPattern {
    
    class RealSubject : Subject {

        public override void Request() {

            Console.WriteLine("Called RealSubject.Request()");
        }
    }
}
