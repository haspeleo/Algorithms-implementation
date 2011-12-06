//---------------------------------------------------------
// StructureAndMethodsThree.cs (c) 2006 by Charles Petzold
//---------------------------------------------------------
using System;

struct Date
{
    public int year;
    public int month;
    public int day;

    public static bool IsLeapYear(int year)
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    static int[] DaysCumulative = { 0, 31, 59, 90, 120, 151,
                                    181, 212, 243, 273, 304, 334 };

    public int DayOfYear()
    {
        return DaysCumulative[month - 1] + day +
            (month > 2 && IsLeapYear(year) ? 1 : 0);
    }
}

class StructureAndMethodsThree
{
    static void Main()
    {
        Date dateMoonWalk = new Date();

        dateMoonWalk.year = 1969;
        dateMoonWalk.month = 7;
        dateMoonWalk.day = 20;

        Console.WriteLine("Moon walk: {0}/{1}/{2} Day of Year: {3}", 
            dateMoonWalk.month, dateMoonWalk.day, dateMoonWalk.year,
            dateMoonWalk.DayOfYear());
    }
}
