// Zadanie 5. Jagoda Pietrusewicz 120A nr albumu 53823

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
	"Marsza³kiewicz",
	"Domko",
	"Harelczak",
};

string dzial[] =
{
	"Bankowoœæ korporacyjna", // 0.
	"Bankowoœæ detaliczna",   // 1.
	"Bezpieczeñstwo",         // 2.
	"IT",                     // 3.  
	"Centrum Pomocy Klienta", // 4.
	"Ksiêgowoœæ",             // 5.
	"HR",                     // 6.
};

//--------------------------------PRACOWNIK-------------------------------------

Pracownik::Pracownik() {

}

Pracownik::~Pracownik() {

}

void Bank::stworzPracownikow() {
	pracownicy = nullptr;
	// bez static pocz¹tkowy stan random_device bêdzie takim sam
	// przy ka¿dym uruchomieniu
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> wymiar(5, 10);

	iloscPracownik = wymiar(dfe);

	pracownicy = new Pracownik * [iloscPracownik];

	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> pensja1Dist(3500, 7000);
	static std::uniform_int_distribution<int> dzialDist(0, 6);

	for (size_t i = 0; i < iloscPracownik; i++) {
		pracownicy[i] = new Pracownik();
		pracownicy[i]->setImiePracownicy(imie[imieDist(dfe)]);
		pracownicy[i]->setNazwiskoPracownicy(nazwisko[nazwiskoDist(dfe)]);
		pracownicy[i]->setPensjaPracownicy(pensja1Dist(dfe));
		pracownicy[i]->setDzialPracownicy(dzial[dzialDist(dfe)]);
	}
}

void Bank::wyswietlPracownikow() {
	cout << "~~~~~~~~~~~ PRACOWNICY ~~~~~~~~~~~" << endl;

	czyIstniejePracownicy();

	for (size_t i = 0; i < iloscPracownik; i++) {
		cout << i + 1 << ". " << pracownicy[i]->getImiePracownicy() << "   " << pracownicy[i]->getNazwiskoPracownicy() << "   "
			<< pracownicy[i]->getPensjaPracownicy() << "   " << pracownicy[i]->getDzialPracownicy() << endl;
	}
}

void Bank::dodawaniePracownik() {
	czyIstniejePracownicy();

	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> pensja3Dist(3500, 7000);
	static std::uniform_int_distribution<int> dzialDist(0, 6);

	Pracownik** temp = new Pracownik * [iloscPracownik + 1];

	for (size_t i = 0; i < iloscPracownik; ++i) {
		temp[i] = pracownicy[i];
	}

	temp[iloscPracownik] = new Pracownik;
	temp[iloscPracownik]->setImiePracownicy(imie[imieDist(dfe)]);
	temp[iloscPracownik]->setNazwiskoPracownicy(nazwisko[nazwiskoDist(dfe)]);
	temp[iloscPracownik]->setPensjaPracownicy(pensja3Dist(dfe));
	temp[iloscPracownik]->setDzialPracownicy(dzial[dzialDist(dfe)]);

	delete[] pracownicy;

	pracownicy = temp;

	++iloscPracownik;
}

void Bank::usunPracownika() {
	czyIstniejePracownicy();

	if (iloscPracownik > 0) {
		Pracownik** temp = new Pracownik * [iloscPracownik - 1];
		delete pracownicy[iloscPracownik - 1];
		size_t j{ 0 };

		for (size_t i = 0; i < iloscPracownik - 1; ++i) {
			temp[j] = pracownicy[i];
			++j;
		}

		delete[] pracownicy;
		pracownicy = temp;
		--iloscPracownik;
	}
}

void Bank::sortowaniePracownik() {
	czyIstniejePracownicy();

	Pracownik* temp;

	for (size_t j = 0; j < iloscPracownik - 1; j++) {
		for (size_t i = 0; i < iloscPracownik - j - 1; i++) {
			if (pracownicy[i]->getPensjaPracownicy() < pracownicy[i + 1]->getPensjaPracownicy()) {
				temp = pracownicy[i];
				pracownicy[i] = pracownicy[i + 1];
				pracownicy[i + 1] = temp;
			}
		}
	}
}

void Bank::wyswietlanieSortowania() {
	czyIstniejePracownicy();

	int choice = 1;

	while (choice != 0) {

		cout << "~~~~~~~~~~~~ WYBÓR DZIA£U: ~~~~~~~~~~~~" << endl;
		cout << "1. Bankowoœæ korporacyjna" << endl;
		cout << "2. Bankowoœæ detaliczna" << endl;
		cout << "3. Bezpieczeñstwo" << endl;
		cout << "4. IT" << endl;
		cout << "5. Centrum Pomocy Klienta" << endl;
		cout << "6. Ksiêgowoœæ" << endl;
		cout << "7. HR" << endl;
		cout << "0. Wyjœcie" << endl;

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
			cout << "Podano niew³aœciw¹ wartoœæ!" << endl;
			break;
		case 0:
			system("cls");
			break;
		}
	}
}

void Bank::dzialy(int numer_dzialu) {
	bool found = false;

	for (size_t i = 0; i < iloscPracownik; i++) {
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

void Bank::czyIstniejePracownicy() {
	if (getIloscPracownik() == 0) {
		cout << "Tablica pracowników nie istnieje!" << endl;
		return;
	}
}

////-----------------------------------KIEROWNIK-------------------------------------------

Kierownik::Kierownik() {

}

Kierownik::~Kierownik() {

}

// creating the pracownicy array of the Bank class without the >> operator overload
//void Bank::stworzKierownikow() {
//	kierownicy = nullptr;
//
//	static std::random_device rd;
//	static std::mt19937_64 dfe(rd());
//	static std::uniform_int_distribution<int> wymiar(5, 10);
//	iloscKierownik = wymiar(dfe);
//
//	kierownicy = new Kierownik[iloscKierownik];
//
//	static std::uniform_int_distribution<int> imieDist(0, 9);
//	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
//	static std::uniform_int_distribution<int> pensja2Dist(3500, 7000);
//
//	for (size_t i = 0; i < iloscKierownik; i++) {
//		kierownicy[i].setImieKierownicy(imie[imieDist(dfe)]);
//		kierownicy[i].setNazwiskoKierownicy(nazwisko[nazwiskoDist(dfe)]);
//		kierownicy[i].setPensjaKierownicy(pensja2Dist(dfe));
//	}
//}

// creating the pracownicy array of the Bank class with the >> operator overload
void Bank::stworzKierownikow() {
	kierownicy = nullptr;

	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> wymiar(5, 10);
	iloscKierownik = wymiar(dfe);

	kierownicy = new Kierownik[iloscKierownik];
	std::cin >> *this;
}

void Bank::wyswietlKierownikow() {
	cout << "~~~~~~~~~~~ KIEROWNICY ~~~~~~~~~~~" << endl;

	czyIstniejeKierownicy();

	for (size_t i = 0; i < iloscKierownik; i++) {
		cout << i + 1 << ". " << kierownicy[i].getImieKierownicy() << "   " << kierownicy[i].getNazwiskoKierownicy() << "   "
			<< kierownicy[i].getPensjaKierownicy() << endl;
	}
}

void Bank::dodawanieKierownik() {
	czyIstniejeKierownicy();

	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> pensja4Dist(3500, 5000);

	Kierownik* temp = new Kierownik[iloscKierownik + 1];

	for (size_t i = 0; i < iloscKierownik; ++i) {
		temp[i] = kierownicy[i];
	}

	temp[iloscKierownik].setImieKierownicy(imie[imieDist(dfe)]);
	temp[iloscKierownik].setNazwiskoKierownicy(nazwisko[nazwiskoDist(dfe)]);
	temp[iloscKierownik].setPensjaKierownicy(pensja4Dist(dfe));

	delete[] kierownicy;

	kierownicy = temp;

	++iloscKierownik;
}

void Bank::usunKierownika() {
	czyIstniejeKierownicy();

	Kierownik* temp = new Kierownik[iloscKierownik - 1];

	for (size_t i = 0; i < iloscKierownik - 1; ++i) {
		if (i < iloscKierownik) {
			temp[i] = kierownicy[i];
		}
		else {
			break;
		}
	}

	delete[] kierownicy;
	kierownicy = temp;
	--iloscKierownik;
}

void Bank::wprowadzDaneKierownika() {

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Podaj imiê, nazwisko i pensjê kierownika (imiê;nazwisko;pensja;): " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	Kierownik* temp = new Kierownik[iloscKierownik + 1];

	cin.ignore(); //clear buffer before taking new

	string input;
	getline(cin, input);
	size_t pos = 0;
	string token;
	int index = 0; // "index" keeps track of the number of semicolons encountered, so the function knows which data to process

	for (size_t i = 0; i < iloscKierownik; ++i) {
		temp[i] = kierownicy[i];
	}

	// correct input format: "imiê;nazwisko;pensja;"

	while (input.size() > 0) { // loop until the input string is empty
		pos = input.find(';'); // search for the first occurrence of ';'
		if (pos == string::npos) { // if ';' is not found
			cout << "Nieprawid³owy format danych!" << endl;
			delete[] temp;
			return;
		}
		token = input.substr(0, pos); // separate the string from the beginning until ';'
		if (index == 0) { // first ';'
			temp[iloscKierownik].setImieKierownicy(token);
		}
		if (index == 1) { // second ';'
			temp[iloscKierownik].setNazwiskoKierownicy(token);
		}
		if (index == 2) { // third ';'
			bool is_int = true;
			for (char c : token) { // iterate over each character in "token"
				if (!isdigit(c)) { // if the character is not a digit
					is_int = false;
					break;
				}
			}
			if (is_int == true) { // if "token" is an integer
				temp[iloscKierownik].setPensjaKierownicy(stoi(token)); // convert string to int
			}
			else { // if the token is not an integer
				cout << "Wprowadzona wartoœæ pensji nie jest liczb¹ ca³kowit¹!" << endl;
				delete[] temp;
				return;
			}
		}
		input.erase(0, pos + 1); // remove the processed token along with ';'
		index++;
	}

	delete[] kierownicy;
	kierownicy = temp;
	++iloscKierownik;
}

void Bank::czyIstniejeKierownicy() {
	if (getIloscKierownik() == 0) {
		cout << "Tablica kierowników nie istnieje!" << endl;
		return;
	}
}

// the >> operator overload definition
std::istream& operator>>(std::istream& input, Bank& bank) {
	// open the file for reading
	std::ifstream file("kierownicy-input.txt");
	if (!file.is_open()) {
		std::cerr << "Nie mo¿na otworzyæ pliku!" << std::endl;
		return input;
	}

	for (size_t i = 0; i < bank.getIloscKierownik(); i++) {
		std::string imie, nazwisko, pensja_str;
		file >> imie >> nazwisko >> pensja_str;

		int pensja = std::stoi(pensja_str);

		bank.getKierownicy()[i].setImieKierownicy(imie);
		bank.getKierownicy()[i].setNazwiskoKierownicy(nazwisko);
		bank.getKierownicy()[i].setPensjaKierownicy(pensja);
	}

	return input;
}

// the << operator overload definition
std::ostream& operator<<(std::ostream& output, const Bank& bank) {
	// open the file for writing
	std::ofstream file("kierownicy-output.txt");
	if (!file.is_open()) {
		std::cerr << "Nie mo¿na otworzyæ pliku!" << std::endl;
		return output;
	}

	for (size_t i = 0; i < bank.getIloscKierownik(); i++) {
		file << bank.getKierownicy()[i].getImieKierownicy() << " "
			<< bank.getKierownicy()[i].getNazwiskoKierownicy() << " "
			<< bank.getKierownicy()[i].getPensjaKierownicy() << "\n";
	}

	return output;
}

void writeKierownicyToFile(const Bank& bank) {
	std::ofstream file("kierownicy-output.txt");

	file << bank;

	file.close();
}

////------------------------------------------KREDYT----------------------------------------------

Kredyt::Kredyt() {

}

Kredyt::~Kredyt() {

}

void Bank::usunKredyt() {
	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<size_t> losowanieDist(0, iloscKlient - 1);

	size_t osobaLosowana = losowanieDist(dfe);

	size_t rozmiar_kredytow = klienci[osobaLosowana].getRozmiarKredyt();

	if (rozmiar_kredytow <= 1) { // if klient has only one kredyt, set it to 0
		klienci[osobaLosowana].getKredyt()[0]->setKredyt(0);
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
			temp[j++] = klienci[osobaLosowana].getKredyt()[i];
		}
		else {
			delete klienci[osobaLosowana].getKredyt()[i]; // delete the kredyt object
			klienci[osobaLosowana].getKredyt()[i] = nullptr; // set the pointer to null
		}
	}

	delete[] klienci[osobaLosowana].getKredyt();

	klienci[osobaLosowana].setKredyt(temp);
	klienci[osobaLosowana].setRozmiarKredyt(klienci[osobaLosowana].getRozmiarKredyt() - 1);

	if (kredytDoUsuwania >= rozmiar_kredytow) {
		kredytDoUsuwania = rozmiar_kredytow - 1;
	}

	if (klienci[osobaLosowana].getKredyt()[kredytDoUsuwania] == nullptr) { // if the kredyt object is null, set kredyt to 0
		klienci[osobaLosowana].getKredyt()[kredytDoUsuwania] = new Kredyt;
		klienci[osobaLosowana].getKredyt()[kredytDoUsuwania]->setKredyt(0);
	}
}

// printing kredyt without the [] operator overload
//void Bank::wyswietlKredyty() {
//	cout << "~~~~~~~~~~~ KREDYTY ~~~~~~~~~~~" << endl;
//	czyIstniejeKlienci();
//
//	for (size_t i = 0; i < iloscKlient; i++) {
//		cout << i + 1 << ". " << endl;
//		for (size_t j = 0; j < klienci[i].getRozmiarKredyt(); j++) {
//			cout << j + 1 << ". ";
//			cout << klienci[i].getKredyt()[j]->getKredytValue();
//			cout << " - " << klienci[i].getKredyt()[j]->getKredytDate() << " r. " << endl;
//		}
//		cout << "   " << endl;
//	}
//}

// printing kredyt with the [] operator overload
void Bank::wyswietlKredyty() {
	cout << "~~~~~~~~~~~ KREDYTY ~~~~~~~~~~~" << endl;
	czyIstniejeKlienci();
	for (size_t i = 0; i < iloscKlient; i++) {
		cout << i + 1 << ". " << endl;
		for (size_t j = 0; j < klienci[i].getRozmiarKredyt(); j++) {
			cout << j + 1 << ". ";
			cout << klienci[i][j]->getKredytValue();
			cout << " - " << klienci[i][j]->getKredytDate() << " r. " << endl;
		}
		cout << "   " << endl;
	}
}

void Bank::czyIstniejeKredyty() {
	if (getIloscKredyt() == 0) {
		cout << "Tablica kredytów nie istnieje!" << endl;
		return;
	}
}

// the [] operator overload definition
Kredyt* Klient::operator[](const size_t k) {
	return kredyt[k];
}

////-------------------------------------KLIENT-------------------------------------------------

Klient::Klient() {

}

Klient::~Klient() {
	for (size_t i = 0; i < rozmiar_Kredyt; i++) {
		delete kredyt[i];
	}
	delete[] kredyt;
}

// copy constructor of Klient definition
Klient::Klient(const Klient& kopia) {
	imie = kopia.imie;
	nazwisko = kopia.nazwisko;
	rozmiar_Kredyt = kopia.rozmiar_Kredyt;
	kredyt = new Kredyt * [rozmiar_Kredyt];
	for (size_t i = 0; i < rozmiar_Kredyt; i++) {
		kredyt[i] = new Kredyt(*kopia.kredyt[i]);
	}
}

void Bank::stworzKlienci() {

	static std::random_device rd;
	static std::mt19937_64 dfe(rd());
	static std::uniform_int_distribution<size_t> wymiar(5, 10);
	static std::uniform_int_distribution<size_t> rok(1990, 2023);
	iloscKlient = wymiar(dfe);
	iloscKredyt = wymiar(dfe);

	klienci = new Klient[iloscKlient];

	static std::uniform_int_distribution<int> imieDist(0, 9);
	static std::uniform_int_distribution<int> nazwiskoDist(0, 9);
	static std::uniform_int_distribution<int> kredytDist(3500, 7000);

	for (size_t i = 0; i < iloscKlient; i++) {
		klienci[i].setImieKlienci(imie[imieDist(dfe)]);
		klienci[i].setNazwiskoKlienci(nazwisko[nazwiskoDist(dfe)]);
		klienci[i].setKredyt(new Kredyt * [iloscKredyt]);

		// initialize kredyt array
		for (size_t j = 0; j < iloscKredyt; ++j) {
			klienci[i].getKredyt()[j] = new Kredyt;
		}
		klienci[i].setRozmiarKredyt(iloscKredyt);

		// populate the kredyt array
		for (size_t j = 0; j < iloscKredyt; j++) {
			klienci[i].getKredyt()[j] = new Kredyt;
			klienci[i].getKredyt()[j]->setKredyt(kredytDist(dfe));
			klienci[i].getKredyt()[j]->setKredytDate(rok(dfe)); // using befriended class's (KredytHelper's) setter method in Kredyt class
		}
	}
}

void Bank::wyswietlKlienci() {
	cout << "~~~~~~~~~~~ KLIENCI ~~~~~~~~~~~" << endl;

	czyIstniejeKlienci();

	for (size_t i = 0; i < iloscKlient; i++) {
		cout << i + 1 << ". " << endl;
		cout << "Imie: " << endl;
		cout << klienci[i].getImieKlienci() << endl;
		cout << "   " << endl;
		cout << "Nazwisko: " << endl;
		cout << klienci[i].getNazwiskoKlienci() << endl;
		cout << "   " << endl;
		cout << "Kredyty: " << endl;
		for (size_t j = 0; j < klienci[i].getRozmiarKredyt(); j++) {
			cout << j + 1 << ". ";
			cout << klienci[i].getKredyt()[j]->getKredytValue();
			cout << " - " << klienci[i].getKredyt()[j]->getKredytDate() << " r. " << endl; // using befriended class's (KredytHelper's) getter method in Kredyt class
		}
		cout << "   " << endl;
	}

}

void Bank::czyIstniejeKlienci() {
	if (getIloscKlient() == 0) {
		cout << "Tablica klientów nie istnieje!" << endl;
		return;
	}
}

// the = operator overload definition
Klient & Klient::operator=(const Klient& right) {
	if (&right != this) {
		this->Klient::~Klient();
		this->Klient::Klient(right);
	}
	return *this;
}

//---------------------------------------BANK----------------------------------------------

Bank::Bank() {

}

Bank::Bank(const Bank& kopia)
{
	iloscPracownik = kopia.iloscPracownik;
	iloscKierownik = kopia.iloscKierownik;
	iloscKredyt = kopia.iloscKredyt;
	iloscKlient = kopia.iloscKlient;

	pracownicy = new Pracownik * [iloscPracownik];
	for (size_t i = 0; i < iloscPracownik; i++)
	{
		pracownicy[i] = new Pracownik(*kopia.pracownicy[i]);
	}

	kierownicy = new Kierownik[iloscKierownik];
	for (size_t i = 0; i < iloscKierownik; i++)
	{
		kierownicy[i] = kopia.kierownicy[i];
	}

	kredyt = new Kredyt * [iloscKredyt];
	for (size_t i = 0; i < iloscKredyt; i++)
	{
		kredyt[i] = new Kredyt(*kopia.kredyt[i]);
	}

	klienci = new Klient[iloscKlient];
	for (size_t i = 0; i < iloscKlient; i++)
	{
		klienci[i] = kopia.klienci[i];
	}
}

Bank::~Bank() {
	// releasing allocated memory - pracownicy array
	for (size_t i = 0; i < iloscPracownik; i++) {
		delete pracownicy[i];
	}
	delete[] pracownicy;
	pracownicy = nullptr;
	iloscPracownik = 0;

	// releasing allocated memory - kierownicy array
	delete[] kierownicy;
	kierownicy = nullptr;
	iloscKierownik = 0;

	// releasing allocated memory - klienci and kredyt array
	for (size_t i = 0; i < iloscKlient; i++) {
		for (size_t j = 0; j < klienci[i].getRozmiarKredyt(); j++) {
			delete klienci[i].getKredyt()[j];
		}
		delete[] klienci[i].getKredyt();
	}
	delete[] klienci;
	klienci = nullptr;
	iloscKlient = 0;

	kredyt = nullptr;
	iloscKredyt = 0;
}