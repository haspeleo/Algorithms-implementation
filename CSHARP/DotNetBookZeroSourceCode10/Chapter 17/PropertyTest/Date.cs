//-------------------------------------
// Date.cs (c) 2006 by Charles Petzold
//-------------------------------------
using System;

class Date
{
    // Private fields
    int year = 1;
    int month = 1;
    int day = 1;

    // Public properties
    public int Year
    {
        set
        {
            if (!IsConsistent(value, Month, Day))
                throw new ArgumentOutOfRangeException("Year");

            year = value;
        }
        get
        {
            return year; 
        }
    }

    public int Month
    {
        set
        {
            if (!IsConsistent(Year, value, Day))
                throw new ArgumentOutOfRangeException("Month = " + value);

            month = value;
        }
        get
        {
            return month; 
        }
    }

    public int Day
    {
        set
        {
            if (!IsConsistent(Year, Month, value))
                throw new ArgumentOutOfRangeException("Day");

            day = value;
        }
        get
        {
            return day; 
        }
    }

    // Parameterless constructor
    public Date()
    {
    }

    // Parametered constructor
    public Date(int year, int month, int day)
    {
        Year = year;
        Month = month;
        Day = day;
    }

    // Private method used by the properties
    static bool IsConsistent(int year, int month, int day)
    {
        if (year < 1)
            return false;

        if (month < 1 || month > 12)
            return false;

        if (day < 1 || day > 31)
            return false;

        if (day == 31 && (month == 4 || month == 6 ||
                           month == 9 || month == 11))
            return false;

        if (month == 2 && day > 29)
            return false;

        if (month == 2 && day == 29 && !IsLeapYear(year))
            return false;

        return true;
    }

    // Public properties
    public static bool IsLeapYear(int year)
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    static int[] daysCumulative = { 0, 31, 59, 90, 120, 151,
                                    181, 212, 243, 273, 304, 334 };

    public int DayOfYear()
    {
        return daysCumulative[Month - 1] + Day +
            (Month > 2 && IsLeapYear(Year) ? 1 : 0);
    }

    static string[] strMonths = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    public override string ToString()
    {
        return String.Format("{0} {1} {2}", Day, 
            strMonths[Month - 1], Year);
    }
}
