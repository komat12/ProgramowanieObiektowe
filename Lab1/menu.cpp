#include <iostream>
#include "tablica_wysw.h"
#include "menu.h"
#include "tablica.h"
#include "pliki.h"

void menu()
{
	Arkusz arkusz;
	int wybor = 0;

	for (;;)
	{
		wstep();
		std::cin >> wybor;
		std::cout << std::endl;
		switch (wybor)
		{

			case 1:
			{
				int szerokosc = 0, wysokosc = 0, reset = 1; char litera;
				do
				{
					std::cout << "Podaj szerokosc arkusza : ";
					std::cin >> szerokosc;
					std::cout << "Podaj wysokosc arkusza : ";
					std::cin >> wysokosc;
					switch (arkusz.tworzenie_arkusza(szerokosc, wysokosc))
					{
						case 1:
						{
							std::cout << "Niepoprawna szerokosc" << std::endl;
							std::cout << "Czy chcialbys ponownie utworzyc tablice ? (Y/N)" << std::endl;
							std::cin >> litera;
							if (litera == 'Y' || litera == 'y');
							else
							{
								reset = 0;
							}
							break;
						}
						case 2:
						{
							std::cout << "Niepoprawna wysokosc" << std::endl;
							std::cout << "Czy chcialbys ponownie utworzyc tablice ? (Y/N)" << std::endl;
							std::cin >> litera;
							if (litera == 'Y' || litera == 'y');
							else
							{
								reset = 0;
							}
							break;
						}
						default:
						{
							reset = 0;
							break;
						}
					}
				} while (reset);
				break;
			}

			case 2:
			{
				int szerokosc = 0, wysokosc = 0;
				std::cout << "Podaj nowa szerokosc arkusza : ";
				std::cin >> szerokosc;
				std::cout << "Podaj nowa wysokosc arkusza : ";
				std::cin >> wysokosc;
				arkusz.zmiana_rozmiaru(szerokosc, wysokosc);
				break;
			}

			case 3:
			{
				wyswietlanie_arkusza(arkusz);
				break;
			}

			case 4:
			{
				int szerokosc, wysokosc;
				std::string wartosc;
				std::cout << "Podaj koordynaty komorki ktora chcesz modyfikowac : " << std::endl << "Szerokosc : ";
				std::cin >> szerokosc;
				std::cout << "Wysokosc : ";
				std::cin >> wysokosc;
				std::cout << "Wartosc : ";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> wartosc;
				arkusz.zwracanie_komorki(szerokosc, wysokosc)->nadawanie_wartosci(wartosc);
				break;
			}

			case 5:
			{
				int szerokosc, typ;
				std::cout << "Podaj kolumne ktorej komorki maja sie zmienic : ";
				std::cin >> szerokosc;
				std::cout << "Mozliwe typy komorek : " << "\n" << "0. Double" << "\n" << "1. String" << "\n";
				std::cin >> typ;
				arkusz.zmiana_kolumny(szerokosc, typ);
				break;
			}

			case 6:
			{
				zapis(arkusz);
				break;
			}

			case 7:
			{
				arkusz = odczyt();
				break;
			}
			
			case 8:
			{
				int wybor = 0;

				std::cout << "Jaka operacje wykonac :" << std::endl;
				std::cout << "1. Podac najwieksza wartosc" << std::endl;
				std::cout << "2. Podac najmniejsza wartosc" << std::endl;
				std::cout << "3. Podac srednia wartosc" << std::endl;
				std::cout << "4. Zsumowac wartosci" << std::endl << std::endl;

				std::cin >> wybor;

				switch (wybor)
				{
					case 1:
					{
						int szerokosc;
						std::cout << "W ktorej kolumnie podac najwieksza wartosc ?" << std::endl;
						std::cin >> szerokosc;
						std::cout << arkusz.najwieksza_wartosc_kolumna(szerokosc) << std::endl;
						break;
					}

					case 2:
					{
						int szerokosc;
						std::cout << "W ktorej kolumnie podac najmniejsza wartosc ?" << std::endl;
						std::cin >> szerokosc;
						std::cout << arkusz.najmniejsza_wartosc_kolumna(szerokosc) << std::endl;
						break;
					}

					case 3:
					{
						int szerokosc;
						std::cout << "W ktorej kolumnie podac srednia wartosc ?" << std::endl;
						std::cin >> szerokosc;
						std::cout << arkusz.srednia_wartosc_kolumna(szerokosc) << std::endl;
						break;
					}

					case 4:
					{
						int szerokosc;
						std::cout << "Wartosci ktorej kolumny zsumowac ?" << std::endl;
						std::cin >> szerokosc;
						std::cout << arkusz.suma_wartosc_kolumna(szerokosc) << std::endl;
						break;
					}

					default:
					{
						break;
					}
				}
				break;
			}

			case 0:
			{
				exit(0);
			}

			default:
			{
				break;
			}

		}
	}

}