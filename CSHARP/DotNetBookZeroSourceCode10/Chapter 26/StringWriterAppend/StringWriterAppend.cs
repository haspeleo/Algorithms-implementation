//---------------------------------------------------
// StringWriterAppend.cs (c) 2006 by Charles Petzold
//---------------------------------------------------
using System;
using System.Diagnostics;
using System.IO;

class StringWriterAppend
{
    const int iterations = 10000;

    public static void Main()
    {
        StringWriter writer = new StringWriter();
        Stopwatch watch = new Stopwatch();
        watch.Start();

        for (int i = 0; i < iterations; i++)
            writer.WriteLine("abcdefghijklmnopqurstuvxyz");

        string str = writer.ToString();
        watch.Stop();
        Console.WriteLine(watch.ElapsedMilliseconds);
    }
}
