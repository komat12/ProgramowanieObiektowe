#include <iostream>
#include "tablica.h"

void wstep()
{
	std::cout << std::endl << "Podany program jest arkuszem kalkulacyjnym" << std::endl;
	std::cout << "__________________________________________" << std::endl;
	std::cout << "Program moze tworzyc oraz edytowac arkusze" << std::endl;
	std::cout << "Co chcesz zrobic ?" << std::endl;
	std::cout << "1. Utworzenie arkusza" << std::endl;
	std::cout << "2. Zmienic wielkosc arkusza." << std::endl;
	std::cout << "3. Wyswietlic arkusz" << std::endl;
	std::cout << "4. Zmodyfikowac wartosci komorki" << std::endl;
	std::cout << "5. Zmienic typ komorek w kolumnie" << std::endl;
	std::cout << "6. Zapisac arkusz do pliku" << std::endl;
	std::cout << "7. Wczytac arkusz z pliku" << std::endl;
	std::cout << "8. Wykonac operacje na kolumnach" << std::endl;
	std::cout << "0. Zakonczyc program" << std::endl << std::endl;
}

void wyswietlanie_arkusza(Arkusz arkusz)
{
	std::string wartosc;
	for (int i = 0; i < arkusz.zwracanie_wysokosci(); i++)
	{
		for (int j = 0; j < arkusz.zwracanie_szerokosci(); j++)
		{
			wartosc = (arkusz.zwracanie_komorki(j, i)->zwracanie_wartosci());
			std::cout << wartosc << "\t";
		}
		std::cout << std::endl << std::endl;
	}
}