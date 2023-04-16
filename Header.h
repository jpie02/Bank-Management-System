// Zadanie 5. Jagoda Pietrusewicz 120A nr albumu 53823

#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <ctime>
#include <string>
#include <random>
#include <fstream>

using namespace std;

class Pracownik {
	string imie;
	string nazwisko;
	string dzial;
	int pensja = 0;
public:
	Pracownik();
	~Pracownik();

	string getImiePracownicy() const { return imie; }
	string getNazwiskoPracownicy() const { return nazwisko; }
	string getDzialPracownicy() const { return dzial; }
	int getPensjaPracownicy() const { return pensja; }

	void setImiePracownicy(string a) { imie = a; }
	void setNazwiskoPracownicy(string a) { nazwisko = a; }
	void setDzialPracownicy(string a) { dzial = a; }
	void setPensjaPracownicy(int value) { pensja = value; }
};

class Kierownik {
	string imie;
	string nazwisko;
	int pensja = 0;
public:
	Kierownik();
	~Kierownik();

	string getImieKierownicy() const { return imie; }
	string getNazwiskoKierownicy() const { return nazwisko; }
	int getPensjaKierownicy() const { return pensja; }

	void setImieKierownicy(string a) { imie = a; }
	void setNazwiskoKierownicy(string a) { nazwisko = a; }
	void setPensjaKierownicy(int value) { pensja = value; }
};

class Kredyt {
	// helper class
	class KredytHelper {
		friend class Kredyt; // declare KredytHelper as a friend class

		int data_kredytu = 0;
	public:
		KredytHelper() {}
		~KredytHelper() {}
	};

	int kredyt = 0;

	// creating and instance of KredytHelper
	KredytHelper KredytHelperNestedClass;
public:
	Kredyt();
	~Kredyt();

	int getKredytValue() const { return kredyt; }

	// befriended class getter method
	int getKredytDate() const { return KredytHelperNestedClass.data_kredytu; }

	void setKredyt(int value) { kredyt = value; };

	// befriended class setter method
	void setKredytDate(int value) { KredytHelperNestedClass.data_kredytu = value; };
};

class Klient {
	string imie;
	string nazwisko;
	Kredyt** kredyt; // array of pointers to Kredyt class
	size_t rozmiar_Kredyt;
public:
	Klient();
	~Klient();
	Klient(const Klient& kopia); // copy constructor of Klient

	string getImieKlienci() const { return imie; }
	string getNazwiskoKlienci() const { return nazwisko; }
	Kredyt** getKredyt() const { return kredyt; }
	size_t getRozmiarKredyt() const { return rozmiar_Kredyt; }

	void setImieKlienci(string a) { imie = a; }
	void setNazwiskoKlienci(string a) { nazwisko = a; }
	void setRozmiarKredyt(size_t a) { rozmiar_Kredyt = a; }
	void setKredyt(Kredyt** a) { kredyt = a; }

	// the [] operator overload
	Kredyt* operator[](const size_t);

	// the = operator overload
	Klient& operator=(const Klient&);
};

class Bank {
	Pracownik** pracownicy;
	Kierownik* kierownicy;
	Kredyt** kredyt;
	Klient* klienci;

	size_t iloscPracownik;
	size_t iloscKierownik;
	size_t iloscKredyt;
	size_t iloscKlient;
public:
	Bank();
	~Bank();
	Bank(const Bank& kopia); // copy constructor of Bank

	size_t getIloscPracownik() const { return iloscPracownik; }
	size_t getIloscKierownik() const { return iloscKierownik; }
	size_t getIloscKredyt() const { return iloscKredyt; }
	size_t getIloscKlient() const { return iloscKlient; }
	Pracownik** getPracownicy() const { return pracownicy; }
	Kierownik* getKierownicy() const { return kierownicy; }

	void setIloscPracownik(size_t a) { iloscPracownik = a; }
	void setiloscKierownik(size_t a) { iloscKierownik = a; }
	void setiloscKredyt(size_t a) { iloscKredyt = a; }
	void setIiloscKlient(size_t a) { iloscKlient = a; }
	void setPracownicy(Pracownik** a) { pracownicy = a; }
	void setKierownicy(Kierownik* a) { kierownicy = a; }

	void stworzPracownikow();
	void wyswietlPracownikow();
	void dodawaniePracownik();
	void usunPracownika();
	void sortowaniePracownik();
	void wyswietlanieSortowania();
	void dzialy(int numer_dzialu);
	void stworzKierownikow();
	void wyswietlKierownikow();
	void dodawanieKierownik();
	void usunKierownika();
	void usunKredyt();
	void stworzKlienci();
	void wyswietlKlienci();
	void wyswietlKredyty();
	void wprowadzDaneKierownika();
	void czyIstniejePracownicy();
	void czyIstniejeKierownicy();
	void czyIstniejeKredyty();
	void czyIstniejeKlienci();

	// the >> operator overload (read from file)
	friend std::istream& operator>>(std::istream& input, Bank& bank);

	// the << operator overload (read to file)
	friend std::ostream& operator<<(std::ostream& output, const Bank& bank);

};

void writeKierownicyToFile(const Bank& bank);

#endif