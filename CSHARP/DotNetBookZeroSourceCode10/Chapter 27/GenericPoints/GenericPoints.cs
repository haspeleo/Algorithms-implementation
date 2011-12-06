//----------------------------------------------
// GenericPoints.cs (c) 2006 by Charles Petzold
//----------------------------------------------
using System;

class GenericPoints
{
    static void Main()
    {
        // Points based on integers
        Point<int> pti1 = new Point<int>();
        Point<int> pti2 = new Point<int>(5, 3);

        Console.WriteLine(pti1.DistanceTo(pti2));

        // Points based on doubles
        Point<double> ptd1 = new Point<double>(13.5, 15);
        Point<double> ptd2 = new Point<double>(3.54, 5E-1);

        Console.WriteLine(ptd2.DistanceTo(ptd1));

        // Points based on strings
        Point<string> pts1 = new Point<string>("34", "27");
        Point<string> pts2 = new Point<string>("0", "0");

        Console.WriteLine(pts1.DistanceTo(pts2));
    }
}
