//-------------------------------------------------------
// StructureAndMethodsTwo.cs (c) 2006 by Charles Petzold
//-------------------------------------------------------
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

    static int[] daysCumulative = { 0, 31, 59, 90, 120, 151,
                                    181, 212, 243, 273, 304, 334 };

    public static int DayOfYear(Date dateParam)
    {
        return daysCumulative[dateParam.month - 1] + dateParam.day +
            (dateParam.month > 2 && IsLeapYear(dateParam.year) ? 1 : 0);
    }
}

class StructureAndMethodsTwo
{
    static void Main()
    {
        Date dateMoonWalk = new Date();

        dateMoonWalk.year = 1969;
        dateMoonWalk.month = 7;
        dateMoonWalk.day = 20;

        Console.WriteLine("Moon walk: {0}/{1}/{2} Day of Year: {3}", 
            dateMoonWalk.month, dateMoonWalk.day, dateMoonWalk.year,
            Date.DayOfYear(dateMoonWalk));
    }
}
