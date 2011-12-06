//-------------------------------------------
// SuperDate2.cs (c) 2006 by Charles Petzold
//-------------------------------------------
using System;

partial class SuperDate : ExtendedDate, IComparable
{
    public int CompareTo(object obj)
    {
        if (obj == null)
            return 1;

        if (!(obj is SuperDate))
            throw new ArgumentException();

        return this - (SuperDate)obj;
    }
}

