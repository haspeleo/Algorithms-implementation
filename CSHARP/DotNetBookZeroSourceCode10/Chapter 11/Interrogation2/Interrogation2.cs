//-----------------------------------------------
// Interrogation2.cs (c) 2006 by Charles Petzold
//-----------------------------------------------
using System;

class Interrogation2
{
    static void Main()
    {
        string strFirstName = GetInfo("Enter your first name");
        string strLastName = GetInfo("Enter your last name");
        string strAge = GetInfo("Enter your age");

        ShowInfo(strFirstName, strLastName, strAge);
    }
    static string GetInfo(string strPrompt)
    {
        Console.Write(strPrompt + ": ");
        return Console.ReadLine();
    }
    static void ShowInfo(string strFirstName, string strSurName, 
                         string strYearsOld)
    {
        Console.WriteLine("First name: " + strFirstName);
        Console.WriteLine("Last name: " + strSurName);
        Console.WriteLine("Age: " + strYearsOld);
    }
}
