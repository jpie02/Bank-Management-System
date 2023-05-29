#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <ctime>
#include <string>
#include <random>
#include <fstream>
#include <vector>

using namespace std;

class Pracownik {
	string imie;
	string nazwisko;
	string dzial;
	int pensja = 0;
public:
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
	int getKredytValue() const { return kredyt; }

	// befriended class getter method
	int getKredytDate() const { return KredytHelperNestedClass.data_kredytu; }

	void setKredyt(int value) { kredyt = value; };

	// befriended class setter method
	void setKredytDate(int value) { KredytHelperNestedClass.data_kredytu = value; };
};

// abstract class
class Osoba {
protected:
	string imie;
	string nazwisko;
public:
	Osoba();
	virtual ~Osoba();

	string getImieKlienci() const { return imie; }
	string getNazwiskoKlienci() const { return nazwisko; }

	void setImieKlienci(string a) { imie = a; }
	void setNazwiskoKlienci(string a) { nazwisko = a; }

	// at least one pure virtual function = abstract class
	virtual void wyswietlKlientow() = 0;
	virtual void setDataZalozenia(size_t a) = 0;
	virtual void setKredyt(Kredyt** a) = 0;
	virtual void setSaldo(size_t a) = 0;
	virtual void setOprocentowanie(size_t a) = 0;
	virtual void setRozmiarKredyt(size_t a) = 0;

	// non-pure virtual functions with default value
	virtual size_t getRozmiarKredyt() const { return 0; }
	virtual Kredyt* operator[](const size_t) { return nullptr; } // the [] operator overload
	virtual Kredyt** getKredyt() const { return nullptr; }
};

// inheritance from Osoba
class Klient : public Osoba {
protected:
	size_t data_zalozenia;
public:
	size_t getDataZalozenia() const { return data_zalozenia; }

	void setDataZalozenia(size_t a) override { data_zalozenia = a; }

	// polymorphism
	void wyswietlKlientow() override;
	void setKredyt(Kredyt** a) override {};
	void setSaldo(size_t a) override {};
	void setOprocentowanie(size_t a) override {};
	void setRozmiarKredyt(size_t a) override {};
};

// inheritance from Osoba and Klient
class KlientKontoKredytobiorcy : public Klient {
	Kredyt** kredyt; // array of pointers to Kredyt class
	size_t rozmiar_Kredyt;
public:
	KlientKontoKredytobiorcy();
	~KlientKontoKredytobiorcy();
	KlientKontoKredytobiorcy(const KlientKontoKredytobiorcy& kopia); // copy constructor of KlientKontoKredytobiorcy

	// the = operator overload
	KlientKontoKredytobiorcy& operator=(const KlientKontoKredytobiorcy&);

	// polymorphism
	void wyswietlKlientow() override;
	Kredyt** getKredyt() const override { return kredyt; }
	Kredyt* operator[](const size_t) override;
	size_t getRozmiarKredyt() const override { return rozmiar_Kredyt; }
	void setKredyt(Kredyt** a) override { kredyt = a; }
	void setSaldo(size_t a) override {};
	void setOprocentowanie(size_t a) override {};
	void setRozmiarKredyt(size_t a) override { rozmiar_Kredyt = a; }
};

// inheritance from Osoba and Klient
class KlientKontoOszczednosciowe : public Klient {
	size_t saldo;
	size_t oprocentowanie;
public:
	size_t getSaldo() const { return saldo; }
	size_t getOprocentowanie() const { return oprocentowanie; }

	// polymorphism
	void wyswietlKlientow() override;
	void setDataZalozenia(size_t a) override {};
	void setKredyt(Kredyt** a) override {};
	void setSaldo(size_t a) override { saldo = a; }
	void setOprocentowanie(size_t a) override { oprocentowanie = a; }
	void setRozmiarKredyt(size_t a) override {};
};

class Bank {
    std::vector<Pracownik*> pracownicy;
    std::vector<Kierownik*> kierownicy;
    std::vector<Kredyt*> kredyt;
    std::vector<Osoba*> klienciKontoKredytobiorcy;
    std::vector<Osoba*> klienciKontoOszczednosciowe;
    std::vector<Osoba*> klienci;

    //size_t iloscPracownik;
    //size_t iloscKierownik;
    //size_t iloscKredyt;
    //size_t iloscKlientKontoKredytobiorcy;
    //size_t iloscKlientKontoOszczednosciowe;
    //size_t iloscKlient;

    Bank();
public:
	~Bank();
	static Bank& getInstance(); // public static method
	Bank(const Bank& kopia) = delete; // declaration of the copy constructor of Bank as deleted

	//size_t getIloscPracownik() const { return iloscPracownik; }
	//size_t getIloscKierownik() const { return iloscKierownik; }
	//size_t getIloscKredyt() const { return iloscKredyt; }
	//size_t getIloscKlient() const { return iloscKlient; }
	//size_t getIloscKlientKontoKredytobiorcy() const { return iloscKlientKontoKredytobiorcy; }
	//size_t getIloscKlientKontoOszczednosciowe() const { return iloscKlientKontoOszczednosciowe; }

	vector<Pracownik*> getPracownicy() const { return pracownicy; }
	vector<Kierownik*> getKierownicy() const { return kierownicy; }
	vector<Osoba*> getKlienciKontoKredytobiorcy() const { return klienciKontoKredytobiorcy; }
	vector<Osoba*> getKlienciKontoOszczednosciowe() const { return klienciKontoOszczednosciowe; }
	vector<Osoba*> getKlienci() const { return klienci; }

	//void setIloscPracownik(size_t a) { iloscPracownik = a; }
	//void setiloscKierownik(size_t a) { iloscKierownik = a; }
	//void setiloscKredyt(size_t a) { iloscKredyt = a; }
	//void setIloscKlientKontoKredytobiorcy(size_t a) { iloscKlientKontoKredytobiorcy = a; }
	//void setIloscKlientKontoOszczednosciowe(size_t a) { iloscKlientKontoOszczednosciowe = a; }
	void setPracownicy(vector<Pracownik*> a) { pracownicy = a; }
	void setKierownicy(vector<Kierownik*> a) { kierownicy = a; }

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
	void stworzKlientKontoKredytobiorcy();
	void wyswietlKredyty();
	void wprowadzDaneKierownika();
	void stworzKlientKontoOszczednosciowe();
	void dodawanieKlientKontoOszczednosciowe();
	void usunKlientKontoOszczednosciowe();
	void wyswietlKlient();
	void wyswietlKlientKontoOszczednosciowe();
	void wyswietlKlientKontoKredytobiorcy();

	// the >> operator overload (read from file)
	friend std::istream& operator>>(std::istream& input, Bank& bank);

	// the << operator overload (read to file)
	friend std::ostream& operator<<(std::ostream& output, const Bank& bank);

};

void writeKierownicyToFile(const Bank& bank);

#endif