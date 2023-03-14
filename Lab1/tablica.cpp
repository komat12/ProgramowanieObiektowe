#include <iostream>
#include "tablica_wysw.h"
#include "menu.h"
#include "tablica.h"
#include "pliki.h"
#include <fstream>

int Arkusz::tworzenie_arkusza(int szerokosc, int wysokosc)
{
    if (szerokosc < 1)
    {
        return 1;
    }
    if (wysokosc < 1)
    {
        return 2;
    }

    typy = new int[szerokosc];

    for (int i = 0; i < szerokosc; i++)
    {
        typy[i] = 0;
    }

    Arkusz::szerokosc = szerokosc;
    Arkusz::wysokosc = wysokosc;
    Arkusz::tablica = new Komorka**[Arkusz::szerokosc];
    for (int i = 0; i < Arkusz::szerokosc; i++)
    {
        Arkusz::tablica[i] = new Komorka*[Arkusz::wysokosc];
    }

    for (int i = 0; i < Arkusz::szerokosc; i++)
    {
        for (int z = 0; z < Arkusz::wysokosc; z++)
        {
            Arkusz::tablica[i][z] = new Komorka_double;
        }
    };

    return 0;
}

void Arkusz::zmiana_rozmiaru(int szerokosc, int wysokosc)
{

    Komorka*** tablica_po_zmianie = new Komorka ** [szerokosc];

    for (int k = 0; k < szerokosc; k++)
    {
        tablica_po_zmianie[k] = new Komorka*[wysokosc];
    }

    int* typy_po_zmianie = new int[szerokosc];

    for (int i = 0; i < szerokosc; i++)
    {
        if (this->szerokosc > i)
        {
            typy_po_zmianie[i] = typy[i];
        }
        else
        {
            typy_po_zmianie[i] = 0;
        }
    }

    for (int i = 0; i < szerokosc; i++)
    {
        for (int z = 0; z < wysokosc; z++)
        {
            if (i < this->szerokosc && z < this->wysokosc)
            {
                tablica_po_zmianie[i][z] = tablica[i][z];
            }
            else if (typy_po_zmianie[i] == 0)
            {
                tablica_po_zmianie[i][z] = new Komorka_double;
            }
            else if(typy_po_zmianie[i] == 1)
            {
                tablica_po_zmianie[i][z] = new Komorka_string;
            }
        }
    };

    Arkusz::tablica = tablica_po_zmianie;
    this->typy = typy_po_zmianie;
    Arkusz::szerokosc = szerokosc; 
    Arkusz::wysokosc = wysokosc;

}

void Arkusz::zmiana_kolumny(int szerokosc, int typ)
{
    switch (typ)
    {
        case 0:
        {
            if (typy[szerokosc] == 0);
            else
            {
                for (int i = 0; i < Arkusz::wysokosc; i++)
                {
                    tablica[szerokosc][i] = new Komorka_double;
                }
                typy[szerokosc] = 0;
            }
            break;
        }

        case 1:
        {
            if (typy[szerokosc] == 1);
            else
            {
                for (int i = 0; i < Arkusz::wysokosc; i++)
                {
                    tablica[szerokosc][i] = new Komorka_string;
                }
                typy[szerokosc] = 1;
            }
            break;
        }

        default:
        {
            break;
        }
    }
}

// /////////////////////////////////////////////////

Komorka* Arkusz::zwracanie_komorki(int szerokosc, int wysokosc)
{
    return tablica[szerokosc][wysokosc];
}

// /////////////////////////////////////////////////

int Arkusz::zwracanie_szerokosci()
{
    return szerokosc;
}

int Arkusz::zwracanie_wysokosci()
{
    return wysokosc;
}

int Arkusz::zwracanie_typow(int szerokosc)
{
    return typy[szerokosc];
}


void Arkusz::nadawanie_szerokosci(int szerokosc)
{
    Arkusz::szerokosc = szerokosc;
}

void Arkusz::nadawanie_wysokosci(int wysokosc)
{
    Arkusz::wysokosc = wysokosc;
}

void Arkusz::nadawanie_typow(int* typy)
{
    Arkusz::typy = typy;
}


// /////////////////////////////////////////////////

double Arkusz::najwieksza_wartosc_kolumna(int szerokosc)
{
    double wynik;
    try
    {
        wynik = stod(Arkusz::zwracanie_komorki(szerokosc, 0)->zwracanie_wartosci());
        for (int i = 0; i < Arkusz::zwracanie_wysokosci(); i++)
        {
            if (wynik < stod(Arkusz::zwracanie_komorki(szerokosc, i)->zwracanie_wartosci()))
            {
                wynik = stod(Arkusz::zwracanie_komorki(szerokosc, i)->zwracanie_wartosci());
            }
        }
        return wynik;
    }
    catch(...)
    {
        std::cout << "W podanej kolumnie nie ma liczb" << "\n";
    }
}

// /////////////////////////////////////////////////

double Arkusz::najmniejsza_wartosc_kolumna(int szerokosc)
{
    double wynik;
    try
    {
        wynik = stod(Arkusz::zwracanie_komorki(szerokosc, 0)->zwracanie_wartosci());
        for (int i = 0; i < Arkusz::zwracanie_wysokosci(); i++)
        {
            if (wynik > stod(Arkusz::zwracanie_komorki(szerokosc, i)->zwracanie_wartosci()))
            {
                wynik = stod(Arkusz::zwracanie_komorki(szerokosc, i)->zwracanie_wartosci());
            }
        }
        return wynik;
    }
    catch(...)
    {
        std::cout << "W podanej kolumnie nie ma liczb" << "\n";
    }
}


// /////////////////////////////////////////////////

double Arkusz::suma_wartosc_kolumna(int szerokosc)
{
    double wynik = 0;
    try
    {
        for (int i = 0; i < Arkusz::zwracanie_wysokosci(); i++)
        {
            wynik += stod(Arkusz::zwracanie_komorki(szerokosc, i)->zwracanie_wartosci());
        }
        return wynik;
    }
    catch(...)
    {
        std::cout << "W podanej kolumnie nie ma liczb" << "\n";
    }
}

// /////////////////////////////////////////////////

double Arkusz::srednia_wartosc_kolumna(int szerokosc)
{
    double wynik = 0;
    try
    {
        for (int i = 0; i < Arkusz::zwracanie_wysokosci(); i++)
        {
            wynik += stod(Arkusz::zwracanie_komorki(szerokosc, i)->zwracanie_wartosci());
        }
        wynik = wynik / (Arkusz::wysokosc);
        return wynik;
    }
    catch(...)
    {
        std::cout << "W podanej kolumnie nie ma liczb" << "\n";
    }
}

// /////////////////////////////////////////////////

std::string Komorka_double::zwracanie_wartosci()
{
    return std::to_string(wartosc);
}

void Komorka_double::nadawanie_wartosci(std::string wartosc)
{
    try 
    { 
        this->wartosc = std::stod(wartosc);
    }
    catch (...) 
    {
        this->wartosc = 0;
    }
}

// /////////////////////////////////////////////////

std::string Komorka_string::zwracanie_wartosci()
{
    return wartosc;
}

void Komorka_string::nadawanie_wartosci(std::string wartosc)
{
    this->wartosc = wartosc;
}