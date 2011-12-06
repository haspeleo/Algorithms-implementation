//----------------------------------------------
// WildCardHexDump.cs © 2001 by Charles Petzold
//----------------------------------------------
using System;
using System.IO;

class WildCardHexDump: HexDump
{
     public new static int Main(string[] strArgs)
     {
         if (strArgs.Length > 0)
         {
             foreach (string strFileName in strArgs)
                 ExpandWildCard(strFileName);
         }
         else
         {
             string strFileName;

             do
             {
                 Console.Write("Enter filename (or Enter to end): ");
                 strFileName = Console.ReadLine();
                 if (strFileName.Length > 0)
                     ExpandWildCard(strFileName);
             }
             while (strFileName.Length > 0);
         }
         return 0;
     }
     static void ExpandWildCard(string strWildCard)
     {
          string[] strFiles; 

          try
          {
               strFiles = Directory.GetFiles(strWildCard);
          }
          catch 
          {
               try
               {
                    string strDir  = Path.GetDirectoryName(strWildCard);
                    string strFile = Path.GetFileName(strWildCard);

                    if (strDir == null || strDir.Length == 0)
                         strDir = ".";

                    strFiles = Directory.GetFiles(strDir, strFile);
               }
               catch
               {
                    Console.WriteLine(strWildCard + ": No Files found!");
                    return;
               }
          }
          if (strFiles.Length == 0)
               Console.WriteLine(strWildCard + ": No files found!");

          foreach(string strFile in strFiles)
               DumpFile(strFile);
     }
}
