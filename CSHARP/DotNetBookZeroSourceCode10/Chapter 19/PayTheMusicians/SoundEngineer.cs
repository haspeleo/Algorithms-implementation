//----------------------------------------------
// SoundEngineer.cs (c) 2006 by Charles Petzold
//----------------------------------------------
class SoundEngineer: Musician
{
    public SoundEngineer(string strName): base(strName)
    {
    }
    public override decimal CalculatePay()
    {
        return 1.25m * base.CalculatePay();
    }
}

