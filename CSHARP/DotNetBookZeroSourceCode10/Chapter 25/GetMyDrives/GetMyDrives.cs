//--------------------------------------------
// GetMyDrives.cs (c) 2006 by Charles Petzold
//--------------------------------------------
using System;
using System.IO;

class GetMyDrives
{
    static void Main()
    {
        DriveInfo[] infos = DriveInfo.GetDrives();

        foreach (DriveInfo info in infos)
        {
            Console.Write("{0} {1}, ", info.Name, info.DriveType);

            if (info.IsReady)
                Console.WriteLine("Label: {0}, Format: {1}, Size: {2:N0}",
                                  info.VolumeLabel, info.DriveFormat, 
                                  info.TotalSize);
            else
                Console.WriteLine("Not ready");
        }
    }
}
