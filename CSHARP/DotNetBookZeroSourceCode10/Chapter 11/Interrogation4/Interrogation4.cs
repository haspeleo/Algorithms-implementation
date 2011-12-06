//-----------------------------------------------
// Interrogation4.cs (c) 2006 by Charles Petzold
//-----------------------------------------------
using System;

class Interrogation4
{
    const string strDelimiter = ": ";
    static string strFirstName, strLastName, strAge;

    static void Main()
    {
        GetInfo();
        ShowInfo();
    }
    static void GetInfo()
    {
        strFirstName = GetInfo("Enter your first name");
        strLastName = GetInfo("Enter your last name");
        strAge = GetInfo("Enter your age");
    }
    static string GetInfo(string strPrompt)
    {
        Console.Write(strPrompt + strDelimiter);
        return Console.ReadLine();
    }
    static void ShowInfo()
    {
        Console.WriteLine();
        Console.WriteLine("First name" + strDelimiter + strFirstName);
        Console.WriteLine("Last name" + strDelimiter + strLastName);
        Console.WriteLine("Age" + strDelimiter + strAge);
    }
}
