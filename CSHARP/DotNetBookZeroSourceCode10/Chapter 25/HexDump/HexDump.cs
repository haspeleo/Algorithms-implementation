//----------------------------------------
// HexDump.cs (c) 2006 by Charles Petzold
//----------------------------------------
using System;
using System.IO;

class HexDump
{
    public static int Main(string[] strArgs)
    {
        if (strArgs.Length > 0)
        {
            foreach (string strFileName in strArgs)
                DumpFile(strFileName);
        }
        else
        {
            string strFileName;

            do
            {
                Console.Write("Enter filename (or Enter to end): ");
                strFileName = Console.ReadLine();
                if (strFileName.Length > 0)
                    DumpFile(strFileName);
            }
            while (strFileName.Length > 0);
        }
        return 0;
    }
    protected static void DumpFile(string strFileName)
    {
        FileStream fs;

        try
        {
            fs = new FileStream(strFileName, FileMode.Open,
                                FileAccess.Read, FileShare.Read);
        }
        catch (Exception exc)
        {
            Console.WriteLine("HexDump: {0}", exc.Message);
            return;
        }
        Console.WriteLine(strFileName);
        DumpStream(fs);
        fs.Close();
    }
    static void DumpStream(Stream stream)
    {
        byte[] buffer = new byte[16];
        long addr = 0;
        int count;

        while ((count = stream.Read(buffer, 0, 16)) > 0)
        {
            Console.WriteLine(ComposeLine(addr, buffer, count));
            addr += 16;
        }
    }
    static string ComposeLine(long addr, byte[] buffer, int count)
    {
        string str = String.Format("{0:X4}-{1:X4}  ",
                            (uint)addr / 65536, (ushort)addr);

        for (int i = 0; i < 16; i++)
        {
            str += (i < count) ?
                           String.Format("{0:X2}", buffer[i]) : "  ";
            str += (i == 7 && count > 7) ? "-" : " ";
        }
        str += " ";

        for (int i = 0; i < 16; i++)
        {
            char ch = (i < count) ? Convert.ToChar(buffer[i]) : ' ';
            str += Char.IsControl(ch) ? "." : ch.ToString();
        }
        return str;
    }
}