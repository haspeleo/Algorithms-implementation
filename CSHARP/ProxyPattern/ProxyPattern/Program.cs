using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProxyPattern {
    
    class MainApp {
    
        static void Main(string[] args) {
        
        //Create a proxy and a request service 

            Proxy proxy = new Proxy();
            proxy.Request();

            //wait for the user
            Console.Read();
        
        
        }
    }
}
