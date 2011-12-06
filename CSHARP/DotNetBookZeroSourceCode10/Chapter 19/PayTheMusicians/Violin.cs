//---------------------------------------
// Violin.cs (c) 2006 by Charles Petzold
//---------------------------------------
class Violin: Musician
{
    int numBrokenStrings;

    public Violin(string strName, int numBrokenStrings): base(strName)
    {
        this.numBrokenStrings = numBrokenStrings;
    }
    public override decimal CalculatePay()
    {
        return 125 - 50 * numBrokenStrings;
    }
}

