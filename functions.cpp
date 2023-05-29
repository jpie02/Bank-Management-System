#include "Header.h"

string imie[] =
{
	"Piotr",
	"Joanna",
	"Martyna",
	"Aleksander",
	"Krzysztof",
	"Julia",
	"Grzegorz",
	"Wiktor",
	"Wioletta",
	"Jagoda",
};

string nazwisko[] =
{
	"Kuchta",
	"Jedynak",
	"Nowak",
	"Gierlik",
	"Krajewiec",
	"Witkiewicz",
	"Kucharczyk",
	"Marszałkiewicz",
	"Domko",
	"Harelczak",
};

string dzial[] =
{
	"Bankowość korporacyjna", // 0.
	"Bankowość detaliczna",   // 1.
	"Bezpieczeństwo",         // 2.
	"IT",                     // 3.  
	"Centrum Pomocy Klienta", // 4.
	"Księgowośc",             // 5.
	"HR",                     // 6.
};

//------------------------------------ PRACOWNIK -----------------------------------------


void Bank::stworzPracownikow() {
	pracownicy.clear();

	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> wymiar(5, 10);

	pracownicy.resize(wymiar(dfe));

	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> pensja1Dist(3500, 7000);
	static std::uniform_int_distribution<int> dzialDist(0, 6);

	for (size_t i = 0; i < pracownicy.size(); i++) {
		pracownicy[i] = new Pracownik();
		pracownicy[i]->setImiePracownicy(imie[imieDist(dfe)]);
		pracownicy[i]->setNazwiskoPracownicy(nazwisko[nazwiskoDist(dfe)]);
		pracownicy[i]->setPensjaPracownicy(pensja1Dist(dfe));
		pracownicy[i]->setDzialPracownicy(dzial[dzialDist(dfe)]);
	}
}

void Bank::wyswietlPracownikow() {
	cout << "~~~~~~~~~~~ PRACOWNICY ~~~~~~~~~~~" << endl;

	for (size_t i = 0; i < pracownicy.size(); i++) {
		cout << i + 1 << ". " << pracownicy[i]->getImiePracownicy() << "   " << pracownicy[i]->getNazwiskoPracownicy() << "   "
			<< pracownicy[i]->getPensjaPracownicy() << "zł   " << pracownicy[i]->getDzialPracownicy() << endl;
	}
}

void Bank::dodawaniePracownik() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> pensja3Dist(3500, 7000);
	static std::uniform_int_distribution<int> dzialDist(0, 6);

	pracownicy.push_back(new Pracownik());
	pracownicy.back()->setImiePracownicy(imie[imieDist(dfe)]);
	pracownicy.back()->setNazwiskoPracownicy(nazwisko[nazwiskoDist(dfe)]);
	pracownicy.back()->setPensjaPracownicy(pensja3Dist(dfe));
	pracownicy.back()->setDzialPracownicy(dzial[dzialDist(dfe)]);
}

void Bank::usunPracownika() {
	if (pracownicy.size() > 0) {
		delete pracownicy.back();
		pracownicy.pop_back();
	}
}

void Bank::sortowaniePracownik() {
	for (size_t j = 0; j < pracownicy.size() - 1; j++) {
		for (size_t i = 0; i < pracownicy.size() - j - 1; i++) {
			if (pracownicy[i]->getPensjaPracownicy() < pracownicy[i + 1]->getPensjaPracownicy()) {
				std::swap(pracownicy[i], pracownicy[i + 1]);
			}
		}
	}
}

void Bank::wyswietlanieSortowania() {
	int choice = 1;

	while (choice != 0) {

		cout << "~~~~~~~~~~~~ WYBÓR DZIAŁU: ~~~~~~~~~~~~" << endl;
		cout << "1. Bankowość korporacyjna" << endl;
		cout << "2. Bankowość detaliczna" << endl;
		cout << "3. Bezpieczeństwo" << endl;
		cout << "4. IT" << endl;
		cout << "5. Centrum Pomocy Klienta" << endl;
		cout << "6. Księgowość" << endl;
		cout << "7. HR" << endl;
		cout << "0. Wyjście" << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			dzialy(0);
			break;
		case 2:
			dzialy(1);
			break;
		case 3:
			dzialy(2);
			break;
		case 4:
			dzialy(3);
			break;
		case 5:
			dzialy(4);
			break;
		case 6:
			dzialy(5);
			break;
		case 7:
			dzialy(6);
			break;
		default:
			cout << "Podano niewłaściwą wartość!" << endl;
			break;
		case 0:
			system("cls");
			break;
		}
	}
}

void Bank::dzialy(int numer_dzialu) {
	bool found = false;

	for (size_t i = 0; i < pracownicy.size(); i++) {
		if (pracownicy[i]->getDzialPracownicy() == dzial[numer_dzialu]) {
			cout << pracownicy[i]->getImiePracownicy() << "   " << pracownicy[i]->getNazwiskoPracownicy() << "   "
				<< pracownicy[i]->getPensjaPracownicy() << "   " << pracownicy[i]->getDzialPracownicy() << endl;
			found = true; // checking if a pracownik in the dzial exists
		}
	}

	if (!found) {
		cout << "Brak pracowników w dziale: " << dzial[numer_dzialu] << endl;
	}
}

//-------------------------------------- KIEROWNIK ----------------------------------------------

// creating the pracownicy array of the Bank class with the >> operator overload
void Bank::stworzKierownikow() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> wymiar(5, 10);
	int iloscKierownik = wymiar(dfe);

	for (int i = 0; i < iloscKierownik; ++i) {
		kierownicy.push_back(new Kierownik);
	}

	std::cin >> *this;
}

void Bank::wyswietlKierownikow() {
	cout << "~~~~~~~~~~~ KIEROWNICY ~~~~~~~~~~~" << endl;

	for (size_t i = 0; i < kierownicy.size(); i++) {
		cout << i + 1 << ". " << kierownicy[i]->getImieKierownicy() << "   " << kierownicy[i]->getNazwiskoKierownicy() << "   "
			<< kierownicy[i]->getPensjaKierownicy() << "zł" << endl;
	}
}

void Bank::dodawanieKierownik() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> pensja4Dist(3500, 5000);

	kierownicy.push_back(new Kierownik());
	kierownicy.back()->setImieKierownicy(imie[imieDist(dfe)]);
	kierownicy.back()->setNazwiskoKierownicy(nazwisko[nazwiskoDist(dfe)]);
	kierownicy.back()->setPensjaKierownicy(pensja4Dist(dfe));
}

void Bank::usunKierownika() {
	if (kierownicy.size() > 0) {
		kierownicy.pop_back();
	}
}

// user input of data for a kierownicy member
void Bank::wprowadzDaneKierownika() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Podaj imię, nazwisko i pensję kierownika (imię;nazwisko;pensja;): " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cin.ignore(); // Clear buffer before taking new

	string input;
	getline(cin, input);
	size_t pos = 0;
	string token;
	int index = 0; // "index" keeps track of the number of semicolons encountered, so the function knows which data to process

	// Correct input format: "imię;nazwisko;pensja;"
	while (input.size() > 0) { // Loop until the input string is empty
		pos = input.find(';'); // Search for the first occurrence of ';'
		if (pos == string::npos) { // If ';' is not found
			cout << "Nieprawidłowy format danych!" << endl;
			return;
		}
		token = input.substr(0, pos); // Separate the string from the beginning until ';'
		if (index == 0) { // First ';'
			Kierownik* kierownik = new Kierownik();
			kierownik->setImieKierownicy(token);
			kierownicy.push_back(kierownik);
		}
		if (index == 1) { // Second ';'
			kierownicy.back()->setNazwiskoKierownicy(token);
		}
		if (index == 2) { // Third ';'
			bool is_int = true;
			for (char c : token) { // Iterate over each character in "token"
				if (!isdigit(c)) { // If the character is not a digit
					is_int = false;
					break;
				}
			}
			if (is_int == true) { // If "token" is an integer
				kierownicy.back()->setPensjaKierownicy(stoi(token)); // Convert string to int
			}
			else { // If the token is not an integer
				cout << "Wprowadzona wartość pensji musi być liczbą całkowitą!" << endl;
				return;
			}
		}
		input.erase(0, pos + 1); // Remove the processed token along with ';'
		index++;
	}
}

// the >> operator overload definition
std::istream& operator>>(std::istream& input, Bank& bank) {
	// open the file for reading
	std::ifstream file("kierownicy-input.txt");
	if (!file.is_open()) {
		std::cerr << "Nie można otworzyć pliku!" << std::endl;
		return input;
	}

	for (size_t i = 0; i < bank.kierownicy.size(); i++) {
		std::string imie, nazwisko, pensja_str;
		file >> imie >> nazwisko >> pensja_str;

		int pensja = std::stoi(pensja_str);

		bank.getKierownicy()[i]->setImieKierownicy(imie);
		bank.getKierownicy()[i]->setNazwiskoKierownicy(nazwisko);
		bank.getKierownicy()[i]->setPensjaKierownicy(pensja);
	}

	return input;
}

// the << operator overload definition
std::ostream& operator<<(std::ostream& output, const Bank& bank) {
	// open the file for writing
	std::ofstream file("kierownicy-output.txt");
	if (!file.is_open()) {
		std::cerr << "Nie można otworzyć pliku!" << std::endl;
		return output;
	}

	for (size_t i = 0; i < bank.kierownicy.size(); i++) {
		file << bank.getKierownicy()[i]->getImieKierownicy() << " "
			<< bank.getKierownicy()[i]->getNazwiskoKierownicy() << " "
			<< bank.getKierownicy()[i]->getPensjaKierownicy() << "\n";
	}

	return output;
}

void writeKierownicyToFile(const Bank& bank) {
	std::ofstream file("kierownicy-output.txt");

	file << bank;

	file.close();
}

//-------------------------------------------- KREDYT ---------------------------------------------------

void Bank::usunKredyt() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<size_t> losowanieDist(0, klienciKontoKredytobiorcy.size() - 1);

	size_t osobaLosowana = losowanieDist(dfe);

	size_t rozmiar_kredytow = klienciKontoKredytobiorcy[osobaLosowana]->getRozmiarKredyt();

	if (rozmiar_kredytow <= 1) { // if klient has only one kredyt, set it to 0
		klienciKontoKredytobiorcy[osobaLosowana]->getKredyt()[0]->setKredyt(0);
		return;
	}

	Kredyt** temp = new Kredyt * [rozmiar_kredytow - 1];

	static std::uniform_int_distribution<size_t> losowanieDistKred(0, rozmiar_kredytow - 1);

	int kredytDoUsuwania = losowanieDistKred(dfe);

	if (kredytDoUsuwania >= rozmiar_kredytow) {
		kredytDoUsuwania = rozmiar_kredytow - 1;
	}

	for (size_t i = 0, j = 0; i < rozmiar_kredytow; ++i) {
		if (i != kredytDoUsuwania) {
			temp[j++] = klienciKontoKredytobiorcy[osobaLosowana]->getKredyt()[i];
		}
		else {
			delete klienciKontoKredytobiorcy[osobaLosowana]->getKredyt()[i];
			klienciKontoKredytobiorcy[osobaLosowana]->getKredyt()[i] = nullptr;
		}
	}

	delete[] klienciKontoKredytobiorcy[osobaLosowana]->getKredyt();

	klienciKontoKredytobiorcy[osobaLosowana]->setKredyt(temp);
	klienciKontoKredytobiorcy[osobaLosowana]->setRozmiarKredyt(klienciKontoKredytobiorcy[osobaLosowana]->getRozmiarKredyt() - 1);

	if (kredytDoUsuwania >= rozmiar_kredytow) {
		kredytDoUsuwania = rozmiar_kredytow - 1;
	}

	if (klienciKontoKredytobiorcy[osobaLosowana]->getKredyt()[kredytDoUsuwania] == nullptr) { // if the kredyt object is null, set kredyt to 0
		klienciKontoKredytobiorcy[osobaLosowana]->getKredyt()[kredytDoUsuwania] = new Kredyt();
		klienciKontoKredytobiorcy[osobaLosowana]->getKredyt()[kredytDoUsuwania]->setKredyt(0);
	}
}

// printing kredyt with the [] operator overload
void Bank::wyswietlKredyty() {
	cout << "~~~~~~~~~~~ KREDYTY ~~~~~~~~~~~" << endl;

	for (size_t i = 0; i < klienciKontoKredytobiorcy.size(); i++) {
		cout << i + 1 << ". " << endl;
		for (size_t j = 0; j < klienciKontoKredytobiorcy[i]->getRozmiarKredyt(); j++) {
			cout << j + 1 << ". ";
			cout << klienciKontoKredytobiorcy[i]->operator[](j)->getKredytValue() << "zł";
			cout << " - " << klienciKontoKredytobiorcy[i]->operator[](j)->getKredytDate() << " r. " << endl;
		}
		cout << "   " << endl;
	}
}

// the [] operator overload definition
Kredyt* KlientKontoKredytobiorcy::operator[](const size_t k) {
	return kredyt[k];
}

//---------------------------------------- OSOBA -------------------------------------------------

Osoba::Osoba() {

}

Osoba::~Osoba() {

}

//--------------------------------------- KLIENT -------------------------------------------------

// printing using polymorphism
void Klient::wyswietlKlientow() {
	cout << getImieKlienci() << "   " << getNazwiskoKlienci() << "   " << getDataZalozenia() << "r. " << endl;
}

void Bank::wyswietlKlient() {
	cout << "~~~~~~~~~~~ KLIENCI I DATY ZAŁOŻENIA KONTA ~~~~~~~~~~~" << endl;

	for (size_t i = 0; i < klienci.size(); i++) {
		klienci[i]->wyswietlKlientow();
	}
}

//-------------------------------- KLIENT KONTO KREDYTOBIORCY ------------------------------------

KlientKontoKredytobiorcy::KlientKontoKredytobiorcy() {

}

KlientKontoKredytobiorcy::~KlientKontoKredytobiorcy() {
	for (size_t i = 0; i < rozmiar_Kredyt; i++) {
		delete kredyt[i];
	}
	delete[] kredyt;
	kredyt = nullptr;
}

// definition of the copy constructor of KlientKontoKredytobiorcy with the inheritance
KlientKontoKredytobiorcy::KlientKontoKredytobiorcy(const KlientKontoKredytobiorcy& kopia)
	: Klient(kopia) // call the copy constructor of the base class
{
	rozmiar_Kredyt = kopia.rozmiar_Kredyt;
	kredyt = new Kredyt * [rozmiar_Kredyt];
	for (size_t i = 0; i < rozmiar_Kredyt; i++) {
		kredyt[i] = new Kredyt(*kopia.kredyt[i]);
	}
}

// creating the klienciKontoKredytobiorcy array
void Bank::stworzKlientKontoKredytobiorcy() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<size_t> wymiar(5, 10);
	static std::uniform_int_distribution<size_t> rok(1990, 2023);
	size_t iloscKlientKontoKredytobiorcy = wymiar(dfe);
	size_t iloscKredyt = wymiar(dfe);

	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> kredytDist(3500, 7000);

	for (size_t i = 0; i < iloscKlientKontoKredytobiorcy; i++) {
		KlientKontoKredytobiorcy* klientKontoKredytobiorcy = new KlientKontoKredytobiorcy;
		klientKontoKredytobiorcy->setImieKlienci(imie[imieDist(dfe)]);
		klientKontoKredytobiorcy->setNazwiskoKlienci(nazwisko[nazwiskoDist(dfe)]);
		klientKontoKredytobiorcy->setKredyt(new Kredyt * [iloscKredyt]);

		klienciKontoKredytobiorcy.push_back(klientKontoKredytobiorcy);

		if (klienci.empty()) {
			klienci.push_back(new Klient);
			klienci[0]->setImieKlienci(imie[imieDist(dfe)]);
			klienci[0]->setNazwiskoKlienci(nazwisko[nazwiskoDist(dfe)]);
			klienci[0]->setDataZalozenia(rok(dfe));
		}
		else {
			klienci.push_back(new Klient);
			klienci.back()->setImieKlienci(imie[imieDist(dfe)]);
			klienci.back()->setNazwiskoKlienci(nazwisko[nazwiskoDist(dfe)]);
			klienci.back()->setDataZalozenia(rok(dfe));
		}

		for (size_t j = 0; j < iloscKredyt; ++j) {
			klientKontoKredytobiorcy->getKredyt()[j] = new Kredyt;
		}
		klientKontoKredytobiorcy->setRozmiarKredyt(iloscKredyt);

		for (size_t j = 0; j < iloscKredyt; j++) {
			klientKontoKredytobiorcy->getKredyt()[j]->setKredyt(kredytDist(dfe));
			klientKontoKredytobiorcy->getKredyt()[j]->setKredytDate(rok(dfe));
		}
	}
}

// printing using polymorphism
void KlientKontoKredytobiorcy::wyswietlKlientow() {

	cout << "Imie: " << getImieKlienci() << endl;
	cout << "Nazwisko: " << getNazwiskoKlienci() << endl;
	cout << "Kredyty: " << endl;
	for (size_t j = 0; j < getRozmiarKredyt(); j++) {
		cout << j + 1 << ". ";
		cout << getKredyt()[j]->getKredytValue();
		cout << " - " << getKredyt()[j]->getKredytDate() << " r. " << endl;
	}
	cout << "   " << endl;
}

void Bank::wyswietlKlientKontoKredytobiorcy() {
	cout << "~~~~~~~~~~~ KLIENCI KREDYTOBIORCY ~~~~~~~~~~~" << endl;

	for (size_t i = 0; i < klienciKontoKredytobiorcy.size(); i++) {
		klienciKontoKredytobiorcy[i]->wyswietlKlientow();
	}
}

// the = operator overload definition
KlientKontoKredytobiorcy& KlientKontoKredytobiorcy::operator=(const KlientKontoKredytobiorcy& right) {
	if (&right != this) {
		this->KlientKontoKredytobiorcy::~KlientKontoKredytobiorcy();
		this->KlientKontoKredytobiorcy::KlientKontoKredytobiorcy(right);
	}
	return *this;
}

//-------------------------------- KLIENT KONTO OSZCZĘDNOŚCIOWE ------------------------------------

// creating the klienciKontoOszczednosciowe array
void Bank::stworzKlientKontoOszczednosciowe() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<size_t> wymiar(5, 10);
	size_t iloscKlientKontoOszczednosciowe = wymiar(dfe);

	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<size_t> saldoDist(1000, 9999);
	static std::uniform_int_distribution<size_t> oprocentowanieDist(1, 8);
	static std::uniform_int_distribution<size_t> rok(1990, 2023);

	for (size_t i = 0; i < iloscKlientKontoOszczednosciowe; i++) {
		int imieIndex = imieDist(dfe);
		int nazwiskoIndex = nazwiskoDist(dfe);

		KlientKontoOszczednosciowe* klientKontoOszczednosciowe = new KlientKontoOszczednosciowe;
		klientKontoOszczednosciowe->setImieKlienci(imie[imieIndex]);
		klientKontoOszczednosciowe->setNazwiskoKlienci(nazwisko[nazwiskoIndex]);
		klientKontoOszczednosciowe->setSaldo(saldoDist(dfe));
		klientKontoOszczednosciowe->setOprocentowanie(oprocentowanieDist(dfe));

		klienciKontoOszczednosciowe.push_back(klientKontoOszczednosciowe);

		// creating the klienci vector
		if (klienci.size() == 0) {
			klienci.push_back(new Klient);
			klienci[0]->setImieKlienci(imie[imieIndex]);
			klienci[0]->setNazwiskoKlienci(nazwisko[nazwiskoIndex]);
			klienci[0]->setDataZalozenia(rok(dfe));
		}
		// adding to an existing klienci vector
		else {
			Klient* klient = new Klient;
			klient->setImieKlienci(imie[imieIndex]);
			klient->setNazwiskoKlienci(nazwisko[nazwiskoIndex]);
			klient->setDataZalozenia(rok(dfe));

			klienci.push_back(klient);
		}
	}
}

// printing using polymorphism
void KlientKontoOszczednosciowe::wyswietlKlientow() {
	cout << ". " << getImieKlienci() << "   " << getNazwiskoKlienci() << "   " << getSaldo() << "zł " << getOprocentowanie() << "%" << endl;
}

void Bank::wyswietlKlientKontoOszczednosciowe() {
	cout << "~~~~~~~~~~~ KONTA OSZCZĘDNOŚCIOWE ~~~~~~~~~~~" << endl;

	for (size_t i = 0; i < klienciKontoOszczednosciowe.size(); i++) {
		klienciKontoOszczednosciowe[i]->wyswietlKlientow();
	}
}

void Bank::dodawanieKlientKontoOszczednosciowe() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<size_t> saldoDist(1000, 99999);
	static std::uniform_int_distribution<size_t> oprocentowanieDist(1, 8);
	static std::uniform_int_distribution<size_t> rok(1990, 2023);

	int imieIndex = imieDist(dfe);
	int nazwiskoIndex = nazwiskoDist(dfe);

	KlientKontoOszczednosciowe* klientKontoOszczednosciowe = new KlientKontoOszczednosciowe;
	klientKontoOszczednosciowe->setImieKlienci(imie[imieIndex]);
	klientKontoOszczednosciowe->setNazwiskoKlienci(nazwisko[nazwiskoIndex]);
	klientKontoOszczednosciowe->setSaldo(saldoDist(dfe));
	klientKontoOszczednosciowe->setOprocentowanie(oprocentowanieDist(dfe));

	klienciKontoOszczednosciowe.push_back(klientKontoOszczednosciowe);

	// creating the klienci vector
	if (klienci.size() == 0) {
		klienci.push_back(new Klient);
		klienci[0]->setImieKlienci(imie[imieIndex]);
		klienci[0]->setNazwiskoKlienci(nazwisko[nazwiskoIndex]);
		klienci[0]->setDataZalozenia(rok(dfe));
	}
	// adding to an existing klienci vector
	else {
		Klient* klient = new Klient;
		klient->setImieKlienci(imie[imieIndex]);
		klient->setNazwiskoKlienci(nazwisko[nazwiskoIndex]);
		klient->setDataZalozenia(rok(dfe));

		klienci.push_back(klient);
	}
}

void Bank::usunKlientKontoOszczednosciowe() {
	if (klienciKontoOszczednosciowe.size() == 0 || klienci.size() == 0) {
		return;  // no elements to remove
	}

	klienciKontoOszczednosciowe.pop_back();

	klienci.pop_back(); 
}

//------------------------------------------ BANK --------------------------------------------------

Bank::Bank() {

}

Bank::~Bank() {

}

Bank& Bank::getInstance()
{
	static Bank INSTANCE;
	return INSTANCE;
}