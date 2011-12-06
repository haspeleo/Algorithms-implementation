//----------------------------------------------------
// TextWithUnicodeChar.cs (c) 2006 by Charles Petzold
//----------------------------------------------------
using System.Windows.Forms;

class TextWithUnicodeChar
{
    public static void Main()
    {
        MessageBox.Show("Hello, Microsoft\x00AE .NET Framework");
    }
}
