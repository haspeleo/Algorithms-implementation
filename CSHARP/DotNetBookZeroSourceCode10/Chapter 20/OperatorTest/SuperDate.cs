//------------------------------------------
// SuperDate.cs (c) 2006 by Charles Petzold
//------------------------------------------
using System;

partial class SuperDate: ExtendedDate
{
    // Constructors
    public SuperDate()
    {
    }
    public SuperDate(int year, int mon, int day): base(year, mon, day)
    {
    }
    public SuperDate(int dayCommonEra)
    {
        CommonEraDay = dayCommonEra;
    }

    // Equality operators
    public static bool operator == (SuperDate sdLeft, SuperDate sdRight)
    {
        return sdLeft.CommonEraDay == sdRight.CommonEraDay;
    }
    public static bool operator != (SuperDate sdLeft, SuperDate sdRight)
    {
        return !(sdLeft == sdRight);
    }
    
    // Relational operators
    public static bool operator < (SuperDate sdLeft, SuperDate sdRight)
    {
        return sdLeft.CommonEraDay < sdRight.CommonEraDay;
    }
    public static bool operator > (SuperDate sdLeft, SuperDate sdRight)
    {
        return sdLeft.CommonEraDay > sdRight.CommonEraDay;
    }
    public static bool operator <= (SuperDate sdLeft, SuperDate sdRight)
    {
        return !(sdLeft > sdRight);
    }
    public static bool operator >= (SuperDate sdLeft, SuperDate sdRight)
    {
        return !(sdLeft < sdRight);
    }

    // Arithmetic operators
    public static SuperDate Add(SuperDate sdLeft, int daysRight)
    {
        return new SuperDate(sdLeft.CommonEraDay + daysRight);
    }
    public static SuperDate operator +(SuperDate sdLeft, int daysRight)
    {
        return Add(sdLeft, daysRight);
    }
    public static SuperDate Add(int daysLeft, SuperDate sdRight)
    {
        return sdRight + daysLeft;
    }
    public static SuperDate operator +(int daysLeft, SuperDate sdRight)
    {
        return Add(sdRight, daysLeft);
    }
    public static int Subtract(SuperDate sdLeft, SuperDate sdRight)
    {
        return sdLeft.CommonEraDay - sdRight.CommonEraDay;
    }
    public static int operator -(SuperDate sdLeft, SuperDate sdRight)
    {
        return Subtract(sdLeft, sdRight);
    }
    public static SuperDate Subtract(SuperDate sdLeft, int daysRight)
    {
        return new SuperDate(sdLeft.CommonEraDay - daysRight);
    }
    public static SuperDate operator -(SuperDate sdLeft, int daysRight)
    {
        return Subtract(sdLeft, daysRight);
    }

    // Unary operators
    public static SuperDate operator ++ (SuperDate sd)
    {
        return new SuperDate(sd.CommonEraDay + 1);
    }
    public static SuperDate operator -- (SuperDate sd)
    {
        return new SuperDate(sd.CommonEraDay - 1);
    }

    // Explicit casts
    public static explicit operator int (SuperDate sd)
    {
        return sd.CommonEraDay;
    }
    public static explicit operator SuperDate (int daysCommonEra)
    {
        return new SuperDate(daysCommonEra);
    }

    // Overrides of methods in System.Object
    public override bool Equals(object obj)
    {
        return obj is SuperDate && this == (SuperDate) obj;
    }
    public override int GetHashCode()
    {
        return CommonEraDay;
    }
}
