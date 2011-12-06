//-----------------------------------------
// Musician.cs (c) 2006 by Charles Petzold
//-----------------------------------------
class Musician
{
    // Private field
    string strName;

    // Public property
    public string Name
    {
        get
        {
            return strName;
        }
    }

    // Constructor
    public Musician(string strName)
    {
        this.strName = strName;
    }

    // Virtual Method
    public virtual decimal CalculatePay()
    {
        return 100;
    }
}
