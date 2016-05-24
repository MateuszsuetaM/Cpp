#include <iostream>

using namespace std;

int wpisz(int *tab, int s) {

  for (int i = 0; i < s; i++) {
    // suma += *tab;
    // *tab = 999;
    // tab++;
    tab[i] = 0;
  }
  // return suma / ile;
}
int wypisz(int *tab, int s) {
  for (int j = 0; j < s; j++) {
    cout << tab[j];
  }
  cout << endl;
}

int main() {
  int s;
  cout << "Podaj 's'" << endl;
  cin >> s;
  int tablica[s];
  // tablica[0] = 1.5;
  // tablica[1] = 2.3;
  // tablica[2] = 0.75;

  wpisz(tablica, s);
  wypisz(tablica, s);
  // cout << endl << tablica[0];
  // cout << endl << tablica[1];
  // cout << endl << tablica[2];

  return 0;
}
