//---------------------------------------------------
// CurrencyFormatting.cs (c) 2006 by Charles Petzold
//---------------------------------------------------
using System;
using System.Globalization;

class CurrencyFormatting
{
    static void Main()
    {
        double money = 1234567.89;

        Console.WriteLine("InvariantInfo: " + 
            money.ToString("C", NumberFormatInfo.InvariantInfo));

        Console.WriteLine("CurrentInfo:   " + 
            money.ToString("C", NumberFormatInfo.CurrentInfo));
        
        NumberFormatInfo info = new NumberFormatInfo();
        info.CurrencySymbol = "\x20AC";
        info.CurrencyPositivePattern = 3;
        info.CurrencyNegativePattern = 8;

        Console.WriteLine("Custom Info:   " + money.ToString("C", info));
    }
}

