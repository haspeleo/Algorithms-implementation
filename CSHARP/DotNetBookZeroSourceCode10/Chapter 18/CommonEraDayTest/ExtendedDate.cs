//---------------------------------------------
// ExtendedDate.cs (c) 2006 by Charles Petzold
//---------------------------------------------
using System;

class ExtendedDate: Date
{
    // Constructors just execute constructors in base class.
    public ExtendedDate()
    {
    }
    public ExtendedDate(int iYear, int iMonth, int iDay): 
                    base(iYear, iMonth, iDay)
    {
    }

    // CommonEraDay sets/gets number of days since beginning of common era.
    public int CommonEraDay
    {
        get
        {
            return DaysBeforeYear() + DayOfYear();
        }
        set
        {
            Day = 1;    // Prevent any inconsistencies during the calculation.

            // Year calculation if leap years were every four years.
            Year = (int)((value - .125m) / 365.25m) + 1;
            int iDayOfYear = value - DaysBeforeYear();

            // Adjust for leap year anomalies every hundred years.
            if (iDayOfYear > (IsLeapYear(Year) ? 366 : 365))
            {
                iDayOfYear -= IsLeapYear(Year) ? 366 : 365;
                Year++;
            }

            // Find the Month and Day
            for (Month = 12; Month > 0; Month--)
            {
                if (iDayOfYear >= DayOfYear())
                {
                    Day = iDayOfYear - DayOfYear() + 1;
                    break;
                }
            }
        }
    }

    // Private method for use by CommonEraDay property.
    int DaysBeforeYear()
    {
        int iYear = Year - 1;

        return (int) (365.25m * iYear) - iYear / 100 + iYear / 400;
    }
}
