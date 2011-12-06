//-------------------------------------------------
// CommonEraDayTest.cs (c) 2006 by Charles Petzold
//-------------------------------------------------
using System;

class CommonEraDayTest
{
    static void Main()
    {
        Console.Write("Enter the year of your birth: ");
        int year = Int32.Parse(Console.ReadLine());

        Console.Write("And the month: ");
        int month = Int32.Parse(Console.ReadLine());

        Console.Write("And the day: ");
        int day = Int32.Parse(Console.ReadLine());

        ExtendedDate exdtBirthday = new ExtendedDate(year, month, day);
        ExtendedDate exdtMoonWalk = new ExtendedDate(1969, 7, 20);

        int daysElapsed = exdtMoonWalk.CommonEraDay - 
                                exdtBirthday.CommonEraDay;

        if (daysElapsed > 0)
            Console.WriteLine(
                "You were born {0:N0} days before the moon walk.",
                daysElapsed);

        else if (daysElapsed == 0)
            Console.WriteLine(
                "You were born on the day of the moon walk.");

        else
            Console.WriteLine(
                "You were born {0:N0} days after the moon walk.",
                -daysElapsed);
    }
}
