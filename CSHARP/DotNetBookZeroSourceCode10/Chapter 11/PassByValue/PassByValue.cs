//--------------------------------------------
// PassByValue.cs (c) 2006 by Charles Petzold
//--------------------------------------------
using System;

class PassByValue
{
    static void Main()
    {
        int i = 22;
        AlterInteger(i);
        Console.WriteLine(i);
    }
    static void AlterInteger(int i)
    {
        i = 55;
    }
}

