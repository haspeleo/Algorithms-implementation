//--------------------------------------------------------
// TestArrayInitialization.cs (c) 2006 by Charles Petzold
//--------------------------------------------------------
using System;
using System.Diagnostics;

class TestArrayInitialization
{
    const int iterations = 10000000;

    static int[] daysCumulativeDays = { 0, 31, 59, 90, 120, 151,
                                    181, 212, 243, 273, 304, 334 };
    
    public static void Main()
    {
        Stopwatch watch = new Stopwatch();
        Random rand = new Random();

        watch.Start();

        for (int i = 0; i < iterations; i++)
            DayOfYear1(rand.Next(1, 13), rand.Next(1, 29));

        watch.Stop();
        Console.WriteLine("Local array:  " + watch.Elapsed);

        watch.Reset();
        watch.Start();

        for (int i = 0; i < iterations; i++)
            DayOfYear2(rand.Next(1, 13), rand.Next(1, 29));

        watch.Stop();
        Console.WriteLine("Static array: " + watch.Elapsed);
    }

    static int DayOfYear1(int month, int day)
    {
        int[] daysCumulative1 = { 0, 31, 59, 90, 120, 151,
                                 181, 212, 243, 273, 304, 334 };

        return daysCumulative1[month - 1] + day;
    }

    static int DayOfYear2(int month, int day)
    {
        return daysCumulativeDays[month - 1] + day;
    }
}

