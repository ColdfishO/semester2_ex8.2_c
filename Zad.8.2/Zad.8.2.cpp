#include <iostream>
#include<locale.h>
using namespace std;
void autor(void) {
    cout << endl;
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "Autor programu: Simon Dudek\n\n";
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "\n\n";
}
template <typename T, int rozmiar>
class wektor {
private:
    T tab[rozmiar];
    int liczba;
public:
    wektor() {
        for (int i = 0;i < rozmiar;i++) {
            tab[i] = NULL;
        }
        liczba = 0;
    }
    wektor(T x) {
        for (int i = 0;i < rozmiar;i++) {
            tab[i] = x;
        }
        liczba = rozmiar;
    }
    int ile_elementów() {
        return liczba;
    }
    T& co_na(int gdzie) {
        if (gdzie < rozmiar && gdzie >= 0) {
            return tab[gdzie];
        }
        else {
            exit(0);
        }
    }
    void wstaw(T obiekt) {
        if (liczba < rozmiar) {
            tab[liczba] = obiekt;
            liczba++;
        }
    }
    void wstaw(T obiekt, int gdzie) {
        if (gdzie < rozmiar && gdzie >= 0) {
            if (liczba < rozmiar) {
                for (int i = rozmiar-1 - gdzie;i > 0;i--) {
                    tab[gdzie + i] = tab[gdzie + i - 1];
                }
                tab[gdzie] = obiekt;
                liczba++;
            }
        }

    }
    void usun() {
        if (liczba > 0) {
            if (tab[liczba - 1] != NULL) {
                tab[liczba - 1] = NULL;
                liczba--;
            }
        }
    }
    void usun(int gdzie) {
        if (gdzie < rozmiar && gdzie >= 0) {
            if (tab[gdzie] != NULL) {
                for (int i = 1;i + gdzie < rozmiar;i++) {
                    tab[gdzie + i - 1] = tab[gdzie + i];
                }
                tab[liczba - 1] = NULL;
                liczba--;
            }
        }
    }
};
int main() {
    setlocale(LC_ALL, "");
    autor();
    int ile;
    int cocal;
    double coprze;
    char coznak;
    wektor<int, 15> calkowite;
    wektor<double, 20> przecinkowe;
    wektor<char, 8> znaki('a');
    calkowite.wstaw(5);
    calkowite.wstaw(6);
    calkowite.wstaw(10);
    calkowite.wstaw(20, 2);
    calkowite.wstaw(2, 1);
    calkowite.usun();
    calkowite.usun(0);
    ile = calkowite.ile_elementów();
    cocal = calkowite.co_na(0);
    cout << "Tablica calkowite ma " << ile << " elementów." << endl;
    cout << "Tablica calkowite ma " << cocal << " na pozycji 0" << endl;
    przecinkowe.wstaw(2.5);
    przecinkowe.wstaw(5.6);
    przecinkowe.wstaw(2.3);
    przecinkowe.wstaw(4.6);
    przecinkowe.wstaw(6.8);
    przecinkowe.wstaw(5.4, 2);
    przecinkowe.usun();
    przecinkowe.usun(3);
    ile = przecinkowe.ile_elementów();
    coprze = przecinkowe.co_na(3);
    cout << "Tablica przecinkowe ma " << ile << " elementów." << endl;
    cout << "Tablica przecinkowe ma " << coprze << " na pozycji 3" << endl;
    znaki.usun();
    znaki.usun();
    znaki.wstaw('d');
    znaki.wstaw('f', 4);
    znaki.usun(3);
    ile = znaki.ile_elementów();
    coznak = znaki.co_na(3);
    cout << "Tablica znaki ma " << ile << " elementów." << endl;
    cout << "Tablica znaki ma " << coznak << " na pozycji 3" << endl;
    system("pause");
    return 0;
}