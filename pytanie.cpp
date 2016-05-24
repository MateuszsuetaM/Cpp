#include "pytanie.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void Pytanie::wczytaj() {
  fstream plik;
  plik.open("quiz.txt", ios::in);
  if (plik.good() == false) {
    cout << "Cos nie tak z plikiem" << endl;
    exit(0);
  }
  int nr_linii = (nr_pytania - 1) * 6 + 1;
  int aktualny_nr = 1;
  string linia;

  while (getline(plik, linia)) {
    if (aktualny_nr == nr_linii)
      tresc = linia;
    if (aktualny_nr == nr_linii + 1)
      a = linia;
    if (aktualny_nr == nr_linii + 2)
      b = linia;
    if (aktualny_nr == nr_linii + 3)
      c = linia;
    if (aktualny_nr == nr_linii + 4)
      d = linia;
    tresc aktualny_nr++;
  }
}

void Pytanie::zadaj() {
  cout << tresc << endl << a << endl << b << endl << c << endl << d << endl;
  cin >> odpowiedz;
  if (odpowiedz == poprawna)
}
