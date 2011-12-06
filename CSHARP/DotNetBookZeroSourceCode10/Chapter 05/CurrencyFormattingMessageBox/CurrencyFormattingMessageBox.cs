//-------------------------------------------------------------
// CurrencyFormattingMessageBox.cs (c) 2006 by Charles Petzold
//-------------------------------------------------------------
using System;
using System.Globalization;
using System.Windows.Forms;

class CurrencyFormatting
{
    static void Main()
    {
        double money = 1234567.89;
        string strDisplay;

        strDisplay = "InvariantInfo: " +
            money.ToString("C", NumberFormatInfo.InvariantInfo) +
            Environment.NewLine;

        strDisplay += "CurrentInfo: " + 
            money.ToString("C", NumberFormatInfo.CurrentInfo) +
            Environment.NewLine;
        
        NumberFormatInfo info = new NumberFormatInfo();
        info.CurrencySymbol = "\x20AC";
        info.CurrencyPositivePattern = 3;
        info.CurrencyNegativePattern = 8;

        strDisplay += "Custom Info: " + money.ToString("C", info);

        MessageBox.Show(strDisplay, "Currency Formatting");
    }
}
