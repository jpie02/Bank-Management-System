// Zadanie 5. Jagoda Pietrusewicz 120A nr albumu 53823

#include "Header.h"

int main()
{
	setlocale(LC_CTYPE, "Polish");

	bool istnieje = false;
	int wybor = 1;

	// creating an instance of the class "Bank" named "bank"
	Bank bank;

	while (wybor != 0) {
		cout << "~~~~~~~~~~~~~~ B A N K ~~~~~~~~~~~~~~" << endl;
		cout << "1. Stwórz tablicę pracowników" << endl;
		cout << "2. Wyświetl pracowników" << endl;
		cout << "3. Dodaj nowego pracownika" << endl;
		cout << "4. Usuń pracownika" << endl;
		cout << "5. Wyświetl pracowników w kolejności od najwięcej zarabiających do najmniej" << endl;
		cout << "6. Wyświetl pracowników wybranego działu" << endl;
		cout << "7. Stwórz tablicę kierowników" << endl;
		cout << "8. Wyświetl kierowników" << endl;
		cout << "9. Dodaj nowego kierownika" << endl;
		cout << "10. Usun kierownika" << endl;
		cout << "11. Stwórz tablicę klientów i kredytów" << endl;
		cout << "12. Wyświetl kredyty" << endl;
		cout << "13. Wyświetl klientów" << endl;
		cout << "14. Usuń kredyt" << endl;
		cout << "15. Dodaj kierownika przez wprowadzanie" << endl;
		cout << "16. Zapisz kierowników do pliku" << endl;

		cout << "0. Wyjście" << endl;

		cin >> wybor;

		switch (wybor) {
		case 1:
			bank.stworzPracownikow();
			system("cls");
			break;
		case 2:
			bank.wyswietlPracownikow();
			break;
		case 3:
			bank.dodawaniePracownik();
			break;
		case 4:
			bank.usunPracownika();
			break;
		case 5:
			bank.sortowaniePracownik();
			bank.wyswietlPracownikow();
			break;
		case 6:
			bank.wyswietlanieSortowania();
			break;
		case 7:
			bank.stworzKierownikow();
			system("cls");
			break;
		case 8:
			bank.wyswietlKierownikow();
			break;
		case 9:
			bank.dodawanieKierownik();
			break;
		case 10:
			bank.usunKierownika();
			break;
		case 11:
			bank.stworzKlienci();
			system("cls");
			break;
		case 12:
			bank.wyswietlKredyty();
			break;
		case 13:
			bank.wyswietlKlienci();
			break;
		case 14:
			bank.usunKredyt();
			break;
		case 15:
			system("cls");
			bank.wprowadzDaneKierownika();
			break;
		case 16:
			writeKierownicyToFile(bank);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Podano niewłaściwą wartość!" << endl;
		}
	}
	return 0;
}