//-------------------------------------------------
// PassArrayByValue.cs (c) 2006 by Charles Petzold
//-------------------------------------------------
using System;

class PassArrayByValue
{
    static void Main()
    {
        int[] arr = new int[10];
        arr[0] = 22;
        AlterInteger(arr);
        Console.WriteLine(arr[0]);
    }
    static void AlterInteger(int[] arr)
    {
        arr[0] = 55;
    }
}
