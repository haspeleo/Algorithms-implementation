//------------------------------------------------
// PassByReference.cs (c) 2006 by Charles Petzold
//------------------------------------------------
using System;

class PassByReference
{
    static void Main()
    {
        int i = 22;
        AlterInteger(ref i);
        Console.WriteLine(i);
    }
    static void AlterInteger(ref int i)
    {
        i = 55;
    }
}

