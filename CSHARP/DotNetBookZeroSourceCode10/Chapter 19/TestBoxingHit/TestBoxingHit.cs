//----------------------------------------------
// TestBoxingHit.cs (c) 2006 by Charles Petzold
//----------------------------------------------
using System;
using System.Diagnostics;

class TestBoxingHit
{
    static void Main()
    {
        const int reps = 100000000;
        Random rand = new Random();
        Stopwatch watch = new Stopwatch();

        // Test method that doesn't involve boxing.
        watch.Start();
        for (int i = 0; i < reps; i++)
            AddIntegers(rand.Next(), rand.Next());
        watch.Stop();

        Console.WriteLine("Method call with no boxing: " + watch.Elapsed);

        // Test method with boxing and unboxing.
        watch.Reset();
        watch.Start();
        for (int i = 0; i < reps; i++)
            AddObjects(rand.Next(), rand.Next());
        watch.Stop();

        Console.WriteLine("Method call with boxing and unboxing: " + 
                            watch.Elapsed);
    }
    static int AddIntegers(int i1, int i2)
    {
        return i1 + i2;
    }
    static int AddObjects(object obj1, object obj2)
    {
        return (int)obj1 + (int)obj2;
    }
}
