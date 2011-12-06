//-----------------------------------------------------
// PassArrayByReference.cs (c) 2006 by Charles Petzold
//-----------------------------------------------------
using System;

class PassArrayByReference
{
    static void Main()
    {
        int[] arr = new int[10];
        arr[0] = 22;
        AlterInteger(ref arr);
        Console.WriteLine(arr[0]);
    }
    static void AlterInteger(ref int[] arr)
    {
        arr[0] = 55;
        arr = new int[5];
    }
}
