//--------------------------------------------
// Inheritance.cs (c) 2006 by Charles Petzold
//--------------------------------------------
using System;

class ExtendedDate : Date
{
    public ExtendedDate()
    {
    }
    public ExtendedDate(int iYear, int iMonth, int iDay) : 
                                base(iYear, iMonth, iDay)
    {
    }
}

class Inheritance
{
    static void Main()
    {
        ExtendedDate dateMoonWalk = new ExtendedDate(1969, 7, 20);

        Console.WriteLine("Moon walk: {0}, Day of Year: {1}", 
            dateMoonWalk, dateMoonWalk.DayOfYear());
    }
}
