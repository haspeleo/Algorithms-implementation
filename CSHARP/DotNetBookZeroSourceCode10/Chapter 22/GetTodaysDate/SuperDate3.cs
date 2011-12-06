//-------------------------------------------
// SuperDate3.cs (c) 2006 by Charles Petzold
//-------------------------------------------
using System;
using System.Runtime.InteropServices;

partial class SuperDate
{
    [StructLayout(LayoutKind.Sequential)]
    class SystemTime
    {
        public ushort wYear;
        public ushort wMonth;
        public ushort wDayOfWeek;
        public ushort wDay;
        public ushort wHour;
        public ushort wMinute;
        public ushort wSecond;
        public ushort wMilliseconds;
    }

    [DllImport("kernel32.dll")]
    static extern void GetSystemTime(SystemTime st);

    public static SuperDate Today()
    {
        SystemTime systime = new SystemTime();
        GetSystemTime(systime);
        return new SuperDate(systime.wYear, systime.wMonth, systime.wDay);
    }
}
