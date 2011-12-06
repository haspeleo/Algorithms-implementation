//---------------------------------------------
// StringAppend.cs (c) 2006 by Charles Petzold
//---------------------------------------------
using System;
using System.Diagnostics;

class StringAppend
{
    const int iterations = 10000;

    public static void Main()
    {
        Stopwatch watch = new Stopwatch();
        string str = String.Empty;

        watch.Start();

        for (int i = 0; i < iterations; i++)
            str += "abcdefghijklmnopqurstuvxyz\r\n";

        watch.Stop();
        Console.WriteLine(watch.ElapsedMilliseconds);
    }
}
