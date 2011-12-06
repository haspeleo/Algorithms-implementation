//--------------------------------------
// Point.cs (c) 2006 by Charles Petzold
//--------------------------------------
using System;
using System.Globalization;

class Point<T> where T:IConvertible
{
    public T X;
    public T Y;
    NumberFormatInfo fmt = NumberFormatInfo.CurrentInfo;

    // Parameterless Constructor
    public Point()
    {
        X = default(T);
        Y = default(T);
    }

    // Two-Parameter Constructor
    public Point(T x, T y)
    {
        X = x;
        Y = y;
    }

    public double DistanceTo(Point<T> pt)
    {
        return Math.Sqrt(Math.Pow(X.ToDouble(fmt) - pt.X.ToDouble(fmt), 2) +
                         Math.Pow(Y.ToDouble(fmt) - pt.Y.ToDouble(fmt), 2));
    }
}
