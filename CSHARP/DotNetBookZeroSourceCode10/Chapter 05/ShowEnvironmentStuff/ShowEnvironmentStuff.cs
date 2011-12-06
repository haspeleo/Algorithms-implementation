//-----------------------------------------------------
// ShowEnvironmentStuff.cs (c) 2006 by Charles Petzold
//-----------------------------------------------------
using System;

class ShowEnvironmentStuff
{
    static void Main()
    {
        Console.WriteLine("My Documents is actually " +
            Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments));
        Console.WriteLine();

        int msec = Environment.TickCount;
        Console.WriteLine("Windows has been running for " +
                          msec + " milliseconds");
        Console.WriteLine("\tor " + msec / 3600000.0 + " hours");
        Console.WriteLine();

        Console.WriteLine("You are running " + Environment.OSVersion);
        Console.WriteLine("\tand .NET version " + Environment.Version);
        Console.WriteLine();
    }
}
