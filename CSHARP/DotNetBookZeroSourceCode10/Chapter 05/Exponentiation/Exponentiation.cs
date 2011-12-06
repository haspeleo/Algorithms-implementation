//-----------------------------------------------
// Exponentiation.cs (c) 2006 by Charles Petzold
//-----------------------------------------------
using System;

class Exponentiation
{
    static void Main()
    {
        Console.Write("Enter the base: ");
        double number = Double.Parse(Console.ReadLine());

        Console.Write("Enter the power: ");
        double power = Double.Parse(Console.ReadLine());

        Console.WriteLine(number + " to the " + power + " power equals " +
                          Math.Pow(number, power));
    }
}
