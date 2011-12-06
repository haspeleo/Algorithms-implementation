//-------------------------------------
// Harp.cs (c) 2006 by Charles Petzold
//-------------------------------------
class Harp: Musician
{
    int weight;

    public Harp(string strName, int weight): base(strName)
    {
        this.weight = weight;
    }
    public override decimal CalculatePay()
    {
        return 1.5m * weight;
    }
}

