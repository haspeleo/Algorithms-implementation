//---------------------------------------------------
// ShowSpecialFolders.cs (c) 2006 by Charles Petzold
//---------------------------------------------------
using System;

class ShowSpecialFolders
{
    static void Main()
    {
        Environment.SpecialFolder[] folders = (Environment.SpecialFolder[])
                        Enum.GetValues(typeof(Environment.SpecialFolder));

        foreach (Environment.SpecialFolder folder in folders)
            Console.WriteLine("{0}: {1}", folder, 
                              Environment.GetFolderPath(folder));
    }
}
