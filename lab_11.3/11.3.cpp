#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Friend {
    string surname;
    string name;
    string zodiac;
    int birthday[3]; // den, misyac, rik
};

// Funktsiya stvorennya faylu
void CreateFile(const char* filename) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Pomilka vidkrittya faylu!" << endl;
        return;
    }
    char ch;
    do {
        Friend fr;
        cout << "Vvedit prizvyshche: ";
        cin >> fr.surname;
        cout << "Vvedit imya: ";
        cin >> fr.name;
        cout << "Vvedit znak zodiaku: ";
        cin >> fr.zodiac;
        cout << "Vvedit den narodzhennya (dd mm rrrr): ";
        cin >> fr.birthday[0] >> fr.birthday[1] >> fr.birthday[2];

        fout << fr.surname << " " << fr.name << " "
            << fr.zodiac << " "
            << fr.birthday[0] << " " << fr.birthday[1] << " "
            << fr.birthday[2] << endl;

        cout << "Prodovzhyty? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

// Funktsiya pereglyadu faylu
void ViewFile(const char* filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Pomilka vidkrittya faylu!" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

// Funktsiya poshuku druziv za misyatsem narodzhennya
void FindByMonth(const char* filename, int month) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Pomilka vidkrittya faylu!" << endl;
        return;
    }
    Friend fr;
    bool found = false;
    while (fin >> fr.surname >> fr.name >> fr.zodiac
        >> fr.birthday[0] >> fr.birthday[1] >> fr.birthday[2]) {
        if (fr.birthday[1] == month) {
            cout << fr.surname << " " << fr.name << " - "
                << fr.zodiac << " (" << fr.birthday[0]
                << "." << fr.birthday[1] << "."
                << fr.birthday[2] << ")" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Nemaye lyudey, narodzhenykh u tsomu misyatsi." << endl;
    }
    fin.close();
}

// Menyu prohramy
void Menu() {
    char filename[100];
    cout << "Vvedit imya faylu: ";
    cin >> filename;

    int choice;
    do {
        cout << "Menyu:\n"
            << "1. Stvoryty fayl\n"
            << "2. Perehlyanuty fayl\n"
            << "3. Znayty druziv za misyatsem narodzhennya\n"
            << "0. Vykhid\n"
            << "Vash vybir: ";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateFile(filename);
            break;
        case 2:
            ViewFile(filename);
            break;
        case 3: {
            int month;
            cout << "Vvedit nomer misyatsya (1-12): ";
            cin >> month;
            if (month < 1 || month > 12) {
                cout << "Nekorektnyy misyats. Sprobuyte shche raz." << endl;
            }
            else {
                FindByMonth(filename, month);
            }
            break;
        }
        case 0:
            cout << "Do pobachennya!" << endl;
            break;
        default:
            cout << "Nekorektnyy vybir. Sprobuyte shche raz." << endl;
        }
    } while (choice != 0);
}

int main() {
    Menu();
    return 0;
}
