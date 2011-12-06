//-------------------------------------------
// FrenchHorn.cs (c) 2006 by Charles Petzold
//-------------------------------------------
class FrenchHorn: Musician
{
    int numGoodNotes, numFlubbedNotes;

    public FrenchHorn(string strName, int numGoodNotes, int numFlubbedNotes):
        base(strName)
    {
        this.numGoodNotes = numGoodNotes;
        this.numFlubbedNotes = numFlubbedNotes;
    }
    public override decimal CalculatePay()
    {
        return 1.5m * numGoodNotes + 0.75m * numFlubbedNotes;
    }
}

