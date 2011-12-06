//----------------------------------------------------
// StringBuilderAppend.cs (c) 2006 by Charles Petzold
//----------------------------------------------------
using System;
using System.Diagnostics;
using System.Text;

class StringBuilderAppend
{
    const int iterations = 10000;

    public static void Main()
    {
        StringBuilder builder = new StringBuilder();
        Stopwatch watch = new Stopwatch();
        watch.Start();

        for (int i = 0; i < iterations; i++)
            builder.Append("abcdefghijklmnopqurstuvxyz\r\n");

        string str = builder.ToString();
        watch.Stop();
        Console.WriteLine(watch.ElapsedMilliseconds);
    }
}
