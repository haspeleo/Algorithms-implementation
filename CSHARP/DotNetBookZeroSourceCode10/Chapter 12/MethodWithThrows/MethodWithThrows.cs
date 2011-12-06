//-------------------------------------------------
// MethodWithThrows.cs (c) 2006 by Charles Petzold
//-------------------------------------------------
using System;

class MethodWithThrows
{
    static void Main()
    {
        uint input;

        Console.Write("Enter an unsigned integer: ");

        try
        {
            input = MyParse(Console.ReadLine());
            Console.WriteLine("You entered {0}", input);
        }
        catch (Exception exc)
        {
            Console.WriteLine(exc.Message);
        }
    }
    static uint MyParse(string str)
    {
        uint result = 0;
        int i = 0;
 
        // If argument is null, throw an exception.
        if (str == null)
            throw new ArgumentNullException();

        // Get rid of white space.
        str = str.Trim();

        // Check if there's at least one character.
        if (str.Length == 0)
            throw new FormatException(); 

        // Loop through all the characters in the string.
        while (i < str.Length)
        {
            // If the next character's not a digit, throw exception.
            if (!Char.IsDigit(str, i))
                throw new FormatException();

            // Accumulate the next digit (notice "checked").
            result = checked(10 * result + (uint) str[i] - (uint) '0');

            i++;
        }
        return result;
    }
}
