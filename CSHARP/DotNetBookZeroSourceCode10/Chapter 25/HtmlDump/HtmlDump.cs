//-----------------------------------------
// HtmlDump.cs (c) 2006 by Charles Petzold
//-----------------------------------------
using System;
using System.IO;
using System.Net;

class HtmlDump
{
    public static void Main()
    {
        Console.Write("Enter a URI: ");
        string strUri = Console.ReadLine();

        if (strUri.Length == 0)
            return;

        WebRequest webreq;
        WebResponse webres;

        try
        {
            webreq = WebRequest.Create(strUri);
            webres = webreq.GetResponse();
        }
        catch (Exception exc)
        {
            Console.WriteLine("HtmlDump: {0}", exc.Message);
            return;
        }

        if (webres.ContentType.Substring(0, 4) != "text")
        {
            Console.WriteLine("HtmlDump: URI must be a text type.");
            return;
        }

        Stream stream = webres.GetResponseStream();
        StreamReader strrdr = new StreamReader(stream);
        string strLine;
        int line = 1;

        while ((strLine = strrdr.ReadLine()) != null)
            Console.WriteLine("{0:D5}: {1}", line++, strLine);

        stream.Close();
        return;
    }
}
