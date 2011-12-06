//------------------------------------------------
// PassParamsArray.cs (c) 2006 by Charles Petzold
//------------------------------------------------
using System;

class PassParamsArray
{
    static void Main()
    {
        int[] arr = { 22, 33, 55, 100, 10, 2 };
        Console.WriteLine(AddUpArray(arr));
        Console.WriteLine(AddUpArray(22, 33, 55, 100, 10, 2));
    }
    static int AddUpArray(params int[] arr)
    {
        int sum = 0;

        foreach (int i in arr)
            sum += i;

        return sum;
    }
}
