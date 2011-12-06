//------------------------------------------------------
// StructureWithToString.cs (c) 2006 by Charles Petzold
//------------------------------------------------------
using System;

struct Date
{
    public int year = 1;
    public int month;
    public int day;

    public static bool IsLeapYear(int year)
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    static int[] daysCumulative = { 0, 31, 59, 90, 120, 151,
                                    181, 212, 243, 273, 304, 334 };

    public int DayOfYear()
    {
        return daysCumulative[month - 1] + day +
            (month > 2 && IsLeapYear(year) ? 1 : 0);
    }

    static string[] strMonths = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    public override string ToString()
    {
        return String.Format("{0} {1} {2}", day, strMonths[month - 1], year);
    }
}

class StructureWithToString
{
    static void Main()
    {
        Date dateMoonWalk = new Date();

        dateMoonWalk.year = 1969;
        dateMoonWalk.month = 7;
        dateMoonWalk.day = 20;

        Console.WriteLine("Moon walk: {0}, Day of Year: {1}", 
            dateMoonWalk, dateMoonWalk.DayOfYear());
    }
}
