//-----------------------------------------------
// MethodCallTest.cs (c) 2006 by Charles Petzold
//-----------------------------------------------
using System;

class MethodCallTest
{
    static void Main()
    {
        PointStruct ps = new PointStruct();
        ps.x = ps.y = 22;

        Console.WriteLine("Before method: ps is ({0}, {1})", ps.x, ps.y);
        ChangeStructure(ps);
        Console.WriteLine("After method:  ps is ({0}, {1})", ps.x, ps.y);

        PointClass pc = new PointClass();
        pc.x = pc.y = 22;

        Console.WriteLine("Before method: pc is ({0}, {1})", pc.x, pc.y);
        ChangeClass(pc);
        Console.WriteLine("After method:  pc is ({0}, {1})", pc.x, pc.y);
    }
    static void ChangeStructure(PointStruct ps)
    {
        ps.x = ps.y = 33;
    }
    static void ChangeClass(PointClass pc)
    {
        pc.x = pc.y = 33;
    }
}
