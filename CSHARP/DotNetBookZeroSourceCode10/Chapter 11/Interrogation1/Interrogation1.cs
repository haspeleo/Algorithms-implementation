//-----------------------------------------------
// Interrogation1.cs (c) 2006 by Charles Petzold
//-----------------------------------------------
using System;

class Interrogation1
{
    static void Main()
    {
        Console.Write("Enter your first name: ");
        string strFirstName = Console.ReadLine();

        Console.Write("Enter your last name: ");
        string strLastName = Console.ReadLine();

        Console.Write("Enter your age: ");
        string strAge = Console.ReadLine();

        Console.WriteLine();
        Console.WriteLine("First name: " + strFirstName);
        Console.WriteLine("Last name: " + strLastName);
        Console.WriteLine("Age: " + strAge);
    }
}
