using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProxyPattern {
    
    class Proxy : Subject {

        RealSubject realSubject;

        public override void Request() {

            //Use lazy initialization 
            if (realSubject == null) {

                realSubject = new RealSubject();
            }

            else {
                realSubject.Request();
            }

        }

    }
}
