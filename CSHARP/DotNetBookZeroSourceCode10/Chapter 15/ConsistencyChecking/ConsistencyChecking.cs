//----------------------------------------------------
// ConsistencyChecking.cs (c) 2006 by Charles Petzold
//----------------------------------------------------
using System;

class Date
{
    public int year;
    public int month;
    public int day;

    // Parameterless constructor
    public Date()
    {
        year = 1;
        month = 1;
        day = 1;
    }

    // Parametered constructor
    public Date(int year, int month, int day)
    {
        if (year < 1)
            throw new ArgumentOutOfRangeException("Year");

        if (month < 1 || month > 12)
            throw new ArgumentOutOfRangeException("Month");

        if (day < 1 || day > 31)
            throw new ArgumentOutOfRangeException("Day");

        if (day == 31 && (month == 4 || month == 6 ||
            month == 9 || month == 11))
            throw new ArgumentOutOfRangeException("Day");

        if (month == 2 && day > 29)
            throw new ArgumentOutOfRangeException("Day");

        if (month == 2 && day == 29 && !IsLeapYear(year))
            throw new ArgumentOutOfRangeException("Day");

        this.year = year;
        this.month = month;
        this.day = day;
    }

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
        return String.Format("{0} {1} {2}", day,
            strMonths[month - 1], year);
    }
}

class ConsistencyChecking
{
    static void Main()
    {
        Date dateDefault = new Date();

        Console.WriteLine("Default Date: {0}", dateDefault);
    }
}
