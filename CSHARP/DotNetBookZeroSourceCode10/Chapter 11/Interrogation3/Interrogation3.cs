//-----------------------------------------------
// Interrogation3.cs (c) 2006 by Charles Petzold
//-----------------------------------------------
using System;

class Interrogation3
{
    static string strFirstName, strLastName, strAge;

    static void Main()
    {
        strFirstName = GetInfo("Enter your first name");
        strLastName = GetInfo("Enter your last name");
        strAge = GetInfo("Enter your age");

        ShowInfo();
    }
    static string GetInfo(string strPrompt)
    {
        Console.Write(strPrompt + ": ");
        return Console.ReadLine();
    }
    static void ShowInfo()
    {
        Console.WriteLine();
        Console.WriteLine("First name: " + strFirstName);
        Console.WriteLine("Last name: " + strLastName);
        Console.WriteLine("Age: " + strAge);
    }
}
