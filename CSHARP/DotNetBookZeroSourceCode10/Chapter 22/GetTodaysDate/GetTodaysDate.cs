//----------------------------------------------
// GetTodaysDate.cs (c) 2006 by Charles Petzold
//----------------------------------------------
using System;

class GetTodaysDate
{
    static void Main()
    {
        SuperDate sdToday = SuperDate.Today();
        Console.WriteLine("Today's date is " + sdToday);
    }
}
