//------------------------------------------------
// PayTheMusicians.cs (c) 2006 by Charles Petzold
//------------------------------------------------
using System;

class PayTheMusicians
{
    static void Main()
    {
        Musician[] musicians = 
            {
                new Musician("Leonard"),
                new Harp("Sam", 62),
                new Violin("Sydney", 0),
                new FrenchHorn("Janet", 46, 23),
                new Musician("Chuck"),
                new Harp("Arien", 78),
                new Violin("Jason", 2),
                new FrenchHorn("Deirdre", 52, 25),
                new SoundEngineer("Fitz")
            };

        foreach (Musician mus in musicians)
            Console.WriteLine("Pay {0} the amount of {1:C}",
                mus.Name, mus.CalculatePay());
    }
}
