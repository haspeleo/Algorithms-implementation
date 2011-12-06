//---------------------------------------------------------
// InputDoublesWithTryParse.cs (c) 2006 by Charles Petzold
//---------------------------------------------------------
using System;

class InputDoublesWithTryParse
{
    static void Main()
    {
        double num = GetDouble("Enter the base: ");
        double exp = GetDouble("Enter the exponent: ");
        Console.WriteLine("{0} to the power of {1} is {2}",
                    num, exp, Math.Pow(num, exp));
    }
    static double GetDouble(string strPrompt)
    {
        double input;
        Console.Write(strPrompt);

        while (!Double.TryParse(Console.ReadLine(), out input))
        {
            Console.WriteLine();
            Console.WriteLine("You typed an invalid number!");
            Console.WriteLine("Please try again: ");
            Console.WriteLine();
            Console.Write(strPrompt);
        }
        return input;
    }
}
