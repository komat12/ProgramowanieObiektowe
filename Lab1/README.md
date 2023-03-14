1. Interfejs uzytkownika :

- wprowadzenie do programu, wyswietlenie czym program jest - cout << "Program polega na..."
- wprowadzenie informacji do programu - cin >> tablica[i] w petli zaleznej od wielkosci tablicy podanej przez uzytkownika
- wyswietlenie informacji jakich operacji na danych mozemy wykonac - "cout" do wyswietlenia mozliwosci, wybor za pomoca "switch"
- po wykonaniu operacji wyswietlenie pytania czy program ma sie wylaczyc czy tez nie - program polega na petli ktora powtarza sie do momentu wybrania opcji wylaczenia
- wyswietlenie zaktualizowanych danych - "cout" zamieszczone w petli zaleznej od wielkosci tablicy
- kontynuowanie programu do momentu az uzytkownik go wylaczy - po probie wylaczenia programu petla na ktorej opiera sie program przestaje sie powtarzac, program zakonczy sie komenda 
return 0;


2. Arkusz :

- Program glowny :

- zapis informacji podanych przez uzytkownika - poprzez komunikacje z interfejsem uzytkownika, zapis za pomoca tabeli
- zapis danych powstalych w wyniku operacji - ewentualne usuniecie juz niepotrzebnych komponentow pomocniczych takich jak np tablica dynamiczna

- Funkcje :

- przeprowadzenie operacji podanej przez uzytkownika - wlaczenie funkcji odpowiedzialnej za dane zadanie (fukcje : zmieniajaca wielkosc tablicy, aktualizujaca zawartosc tablicy, wyswietlajaca zawartosc tablicy)
- przekazanie przetworzonych informacji do programu glownego


3. Pliki :

- Wprowadzanie danych :

- w przypadku gdy arkusz nie został utworzony tworzymy pusty arkusz ktorego wymiary mamy podane w pliku
- w przypadku gdy posiadamy już arkusz mamy 2 opcje :
	- wielkość jest zgodna z rozmiarami podanymi w pliku, wtedy nastepuje zerowanie arkusza i wprowadzanie wartosci podanych w pliku
	- wielkosc nie jest zgodna z rozmiarami podanymi w pliku, wtedy nastepuje usuniecie arkusza, stworzenie nowego arkusza który następnie zostanie "wyzerowany", ostatnia czynnoscia bedzie wczytanie wartosci z pliku do nowo utworzonego arkusza

- Zapisanie danych :

- do pliku tekstowego, za pomoca funkcji, zapisujemy kolejno wielkosc arkusza a nastepnie jego wartosci
