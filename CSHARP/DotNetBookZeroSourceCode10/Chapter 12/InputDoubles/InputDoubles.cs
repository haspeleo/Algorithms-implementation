//---------------------------------------------
// InputDoubles.cs (c) 2006 by Charles Petzold
//---------------------------------------------
using System;

class InputDoubles
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
        double input = Double.NaN;

        do
        {
            Console.Write(strPrompt);

            try
            {
                input = Double.Parse(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine();
                Console.WriteLine("You typed an invalid number!");
                Console.WriteLine("Please try again.");
                Console.WriteLine();
            }
        }
        while (Double.IsNaN(input));

        return input;
    }
}
            
