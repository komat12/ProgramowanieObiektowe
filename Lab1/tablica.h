#include <string>
#pragma once
/// @file

class Komorka
{
public:
	
	/**
	 * @brief Funkcja odbierająca wartość z komórki
	 * @param[out] Wartość Wartość pobierana z komórki
	 */
	virtual std::string zwracanie_wartosci() = 0;

	/**
	 * @brief Funkcja nadająca wartości danej komórce
	 * @param[in] Wartość Wartość nadawana komórce
	 */
	virtual void nadawanie_wartosci(std::string) = 0;

};

class Arkusz
{
private:

	Komorka*** tablica;
	int szerokosc;
	int wysokosc;
	int* typy;

public:

	Arkusz() {}

	/**
	 * @brief Funkcja tworząca arkusz
	 * @param[in] Szerokość Preferowana szerokość arkusza
	 * @param[in] Wysokość Preferowana wysokość arkusza
	 * @param[out] Kod_błędu Zwracany kod błędu
	 */
	int tworzenie_arkusza(int szerokosc, int wysokosc);

	/**
	 * @brief Funkcja modyfikująca wielkość arkusza
	 * @param[in] Szerokość Preferowana szerokość arkusza
	 * @param[in] Wysokość Preferowana wysokość arkusza
	 */
	void zmiana_rozmiaru(int szerokosc, int wysokosc);

	/**
	 * @brief Funkcja zmieniająca typ komórek w danej kolumnie
	 * @param[in] Szerokość Wybrana kolumna
	 * @param[in] Typ Preferowany typ komórek
	 */
	void zmiana_kolumny(int szerokosc, int typ);

	// /////////////////////////////////////////////////

	/**
	 * @brief Funkcja zwracająca komórkę na podanych koordynatach
	 * @param[in] Szerokość Podana szerokość szukanej komórki
	 * @param[in] Wysokość Podana wysokość szukanej komórki
	 * @param[out] Komórka Zwracana komórka
	 */
	Komorka* zwracanie_komorki(int szerokosc, int wysokosc);

	// /////////////////////////////////////////////////

	/**
	 * @brief Funkcja zwracająca szerokość
	 * @param[out] Szerokość Zwracana szerokość
	 */
	int zwracanie_szerokosci();
	
	/**
	 * @brief Funkcja zwracająca szerokość
	 * @param[out] Szerokość Zwracana szerokość
	 */
	int zwracanie_wysokosci();

	/**
	 * @brief Funkcja sprawdzająca typ komórek w kolumnie
	 * @param[in] Szerokość Szerokość na której sprawdzany jest typ
	 * @param[out] Typ Typ komórek w podanej kolumnie
	 */
	int zwracanie_typow(int szerokosc);

	/**
	 * @brief Funkcja nadająca wartość szerokości arkusza
	 * @param[in] Szerokość Nadawana szerokość
	 */  
	void nadawanie_szerokosci(int szerokosc);

	/**
	 * @brief Funkcja nadająca wartość wysokości arkusza
	 * @param[in] Wysokość Nadawana wysokość
	 */
	void nadawanie_wysokosci(int wysokosc);

	/**
	 * @brief Funkcja nadająca wartość typów arkusza
	 * @param[in] Typy Nadawane typy
	 */
	void nadawanie_typow(int* typy);

	// /////////////////////////////////////////////////

	/**
	 * @brief Funkcja pokazująca największą wartość w kolumnie
	 * @param[in] Szerokość Szerokość na której szukana jest wartość
	 * @param[out] Wartość Największa wartość w kolumnie
	 */
	double najwieksza_wartosc_kolumna(int szerokosc);

	// /////////////////////////////////////////////////

	/**
	 * @brief Funkcja pokazująca najmniejszą wartość w kolumnie
	 * @param[in] Szerokość Szerokość na której szukana jest wartość
	 * @param[out] Wartość Najmniejsza wartość w kolumnie
	 */
	double najmniejsza_wartosc_kolumna(int szerokosc);

	// /////////////////////////////////////////////////

	/**
	 * @brief Funkcja pokazująca sumę wartości w kolumnie
	 * @param[in] Szerokość Szerokość z której wartości są sumowane
	 * @param[out] Wartość Suma wartości w kolumnie
	 */
	double suma_wartosc_kolumna(int szerokosc);

	// /////////////////////////////////////////////////

	/**
	 * @brief Funkcja pokazująca średnią wartości w kolumny
	 * @param[in] Szerokość Szerokość z której wartości jest wyliczana średnia
	 * @param[out] Wartość Średnia wartość w kolumnie
	 */
	double srednia_wartosc_kolumna(int szerokosc);

};

class Komorka_double:public Komorka
{

private:
	double wartosc = 0;

public:
	
	/**
	 * @brief Funkcja zwracająca wartość komórki
	 * @param[out] Wartość Wartość danej komórki
	 */
    std::string zwracanie_wartosci();

	/**
	 * @brief Funkcja nadająca wartość komórki
	 * @param[in] Wartość Wartość nadawana danej komórce
	 */
	void nadawanie_wartosci(std::string wartosc);
};

class Komorka_string:public Komorka
{

private:
	std::string wartosc = ".";

public:
	
	/**
	 * @brief Funkcja zwracająca wartość komórki
	 * @param[out] Wartość Wartość danej komórki
	 */
	std::string zwracanie_wartosci();

	/**
	 * @brief Funkcja nadająca wartość komórki
	 * @param[in] Wartość Wartość nadawana danej komórce
	 */
	void nadawanie_wartosci(std::string wartosc);
};
