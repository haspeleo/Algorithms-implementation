//------------------------------------------------------------
// SetTimerWithAnonymousMethod.cs (c) 2006 by Charles Petzold
//------------------------------------------------------------
using System;
using System.Timers;

class SetTimer
{
    static void Main()
    {
        Timer tmr = new Timer();
        tmr.Elapsed += delegate(object sender, ElapsedEventArgs args)
        {
            Console.Write("\r{0} ", args.SignalTime.ToLongTimeString());
        };
        tmr.Interval = 1000;
        tmr.Enabled = true;

        Console.ReadLine();
    }
}
