#include <iostream>
#include "tablica.h"
#include <fstream>

void zapis(Arkusz arkusz)
{
    std::ofstream plik("tablica.txt");
    std::string wartosc;
    if (plik.good())
    {
        plik << arkusz.zwracanie_wysokosci() << std::endl;
        plik << arkusz.zwracanie_szerokosci() << std::endl;

        for (int i = 0; i < arkusz.zwracanie_szerokosci(); i++)
        {
            plik << arkusz.zwracanie_typow(i) << "\t";
        }

        plik << std::endl;

        for (int i = 0; i < arkusz.zwracanie_wysokosci(); i++)
        {
            for (int j = 0; j < arkusz.zwracanie_szerokosci(); j++)
            {
                wartosc = (arkusz.zwracanie_komorki(j, i)->zwracanie_wartosci());
                plik << wartosc << "\t";
            }
            plik << "\n";
        }
        plik.close();
    }
}

Arkusz odczyt()
{
	Arkusz arkusz;
    int szerokosc, wysokosc;
    std::string wartosc;

    std::ifstream plik("tablica.txt");
    plik >> szerokosc; 
    plik >> wysokosc;
    arkusz.nadawanie_szerokosci(szerokosc);
    arkusz.nadawanie_wysokosci(wysokosc);
    
    arkusz.tworzenie_arkusza(szerokosc, wysokosc);
    
    int* typy = new int[arkusz.zwracanie_szerokosci()];

    for (int i = 0; i < arkusz.zwracanie_szerokosci(); i++)
    {
        plik >> typy[i];
        if(typy[i]) arkusz.zmiana_kolumny(i, 1);
    }
    plik.ignore(1000, '\n');

    for (int i = 0; i < arkusz.zwracanie_wysokosci(); i++)
    {
        for (int j = 0; j < arkusz.zwracanie_szerokosci(); j++)
        {
            plik >> wartosc;
            arkusz.zwracanie_komorki(j, i)->nadawanie_wartosci(wartosc);
            plik.clear();
            plik.ignore(1000, '\t');
        }
    }

    arkusz.nadawanie_typow(typy);

    return arkusz;
}