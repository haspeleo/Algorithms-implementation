//--------------------------------------------------------
// SimpleDateStructureDemo.cs (c) 2006 by Charles Petzold
//--------------------------------------------------------
using System;

struct Date
{
    public int year;
    public int month;
    public int day;
}

class SimpleDateStructureDemo
{
    static void Main()
    {
        Date dateMoonWalk;

        dateMoonWalk.year = 1969;
        dateMoonWalk.month = 7;
        dateMoonWalk.day = 20;

        Console.WriteLine("Moon walk: {0}/{1}/{2}", 
            dateMoonWalk.month, dateMoonWalk.day, dateMoonWalk.year);
    }
}
