#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int a, w, s, x, b, q, jest;
int o = 0, do_warunku = 0, warunek = 0;
int z = 0, sto = 1;
char tabe[27] = "abcdefghijklmnopqrstuvwxyz";
string kolorki[24] = {"red",        "green",     "blue",          "yellow",
                      "black",      "pink",      "khaki",         "silver",
                      "brown",      "orange",    "beige",         "violet",
                      "blueviolet", "goldenrod", "cyan",          "bisque",
                      "aqua",       "gray",      "thistle",       "maroon",
                      "orchid",     "deeppink4", "darkgoldenrod", "chocolate4"};
//------------------------------------------------------------------funkcje
void wypelnianie_tablicy(int *tab, int a, int *stos, int *odwiedzone,
                         int **stab, int *kolejnosc);
void sprawdzanie_polaczen(int *tab, int a, int **stab, fstream &graf);
void wyswietlanie_macierzy(int a, int **stab);
void sprawdzanie_parzystosci_wierzcholkow(int *tab);
void DFS(int x, int *stos, int jest, int do_warunku, int *odwiedzone, int sto,
         int z, int o, int **stab);
void LF(int *tab, int a, int *kolejnosc, int **stab, fstream &graf,
        string *kolorki, char *tabe);

void lustereczko_powiedz_przecie(int b, int a);
//------------------------------------------------------------------main
int main() {
  fstream graf;
  graf.open("graf.dot");

  cout << "Podaj ilosc wierzcholkow grafu." << endl;
  cin >> a;
  int stos[a];
  int kolejnosc[a];
  int odwiedzone[a];

  if (a == 0) {
    cout << "Szanowna Pani, ja nie mam tu nic do roboty :)";
  }
  int tab[a];
  int **stab = new int *[a];
  for (int i = 0; i < a; i++)
    stab[i] = new int[a];

  wypelnianie_tablicy(tab, a, stos, odwiedzone, stab, kolejnosc);
  sprawdzanie_polaczen(tab, a, stab, graf);

  wyswietlanie_macierzy(a, stab);
  sprawdzanie_parzystosci_wierzcholkow(tab);
  // if (q == 1) {
  //   cout << "Podany graf nie jest eulerowski" << endl;
  //   return 0;
  // }
  // cout << "Odwiedzone po 1 wierszu: ";
  // for (int c = 0; c < a; c++) {
  //   cout << odwiedzone[c] << ", ";
  // }
  // cout << "Stos: ";
  // for (int c = 0; c < a; c++) {
  //   cout << stos[c] << ", ";
  // }
  // DFS(x, stos, jest, do_warunku, odwiedzone, sto, z, o, stab);
  // int b = 0;
  // for (int c = 0; c < a; c++) {
  //   b += odwiedzone[c];
  // }
  // cout << "Odwiedzone: ";
  // for (int c = 0; c < a; c++) {
  //   cout << odwiedzone[c] << ", ";
  // }
  // cout << "Stos: ";
  // for (int c = 0; c < a; c++) {
  //   cout << stos[c] << ", ";
  // }
  LF(tab, a, kolejnosc, stab, graf, kolorki, tabe);

  //  lustereczko_powiedz_przecie(b, a);
}
//----------------------------------------------------------ciała_funkcji
void wypelnianie_tablicy(int *tab, int a, int *stos, int *odwiedzone,
                         int **stab, int *kolejnosc) {
  for (int it = 0; it < a; it++) {
    tab[it] = 0;
    stos[it] = 0;
    odwiedzone[it] = 0;
    for (int ir = 0; ir < a; ir++) {
      stab[ir][it] = 0;
    }
    kolejnosc[it] = it;
  }
  stos[0] = 0;
  odwiedzone[0] = 1;
}
void sprawdzanie_polaczen(int *tab, int a, int **stab, fstream &graf) {
  // int sprawdzanie_polaczen(int *tab, int *tabe, int a, int **stab) {
  // ofstream graf;
  // graf.open("graf.dot");
  graf << "graph graf{\n";
  int u;
  for (int i = 0; i < a; i++) {
    int w = i + 1;
    for (int j = w; j < a; j++) {
      cout << "Ile jest polaczen miedzy wierzcholkami " << tabe[i] << " i "
           << tabe[j] << "? (jesli zadne to wpisz 0)" << endl;

      cin >> u;
      tab[i] = tab[i] + u;
      tab[j] = tab[j] + u;

      if (u > 0) {
        // stab[i][i]++;
        stab[j][i]++;
        stab[i][j]++;
        while (u > 0) {
          graf << tabe[i] << " -- " << tabe[j] << ";\n";
          u--;
        }
      }
    }
    graf << "\n";
  }
  // graf << "}";
  // graf.close();
}

void wyswietlanie_macierzy(int a, int **stab) {
  for (int it = 0; it < a; it++) { // wyswietlanie macierzy
    for (int ir = 0; ir < a; ir++) {
      cout << stab[ir][it];
    }
    cout << endl;
  }
}
void sprawdzanie_parzystosci_wierzcholkow(int *tab) {
  for (int g = 0; g < a; g++) {
    int as = tab[g];
    if (as % 2 != 0) {
      q = 1;
    }
  }
}

void DFS(int x, int *stos, int jest, int do_warunku, int *odwiedzone, int sto,
         int z, int o, int **stab) {

  while (warunek < 1) {

    int tak = 0;
    x = stos[z];
    for (int y = 0; y < a; y++) { // sprawdzanie linii
      jest = 0;
      if (stab[x][y] > 0) {
        do_warunku++;
        for (int s = 0; s < a; s++) { // sprawdzanie czy "y" jest na stosie
          if (stos[s] == y) {
            tak++;
            jest++;
            break;
          }
        }
        if (jest > 0) {
        } else { ///////////////////////jesli "y" nie jest na stosie to dodaje
          stos[sto] = y; //////////////////// je do stosu i do odwiedzonych
          odwiedzone[y] = 1;
          sto++;
        }
      }
      for (int l = 0; l < a; l++) { ///////sprawdzanie odwiedzonych
        o += odwiedzone[l];
      }
      if (o == a) {
        warunek = 1;
      } else {
        o = 0;
      }
    }
    if (do_warunku == tak) {
      warunek = 1;
    }
    do_warunku = 0;
    tak = 0;
    jest = 0;
    z++;
  }
}
void LF(int *tab, int a, int *kolejnosc, int **stab, fstream &graf,
        string *kolorki, char *tabe) {

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a - 1; j++) {
      if (tab[j] < tab[j + 1]) {
        swap(tab[j], tab[j + 1]);
        swap(kolejnosc[j], kolejnosc[j + 1]);
      }
    }
  }
  for (int oo = 0; oo < a; oo++) {
    cout << kolejnosc[oo] << ", ";
  }
  cout << endl;
  int kolor[a];
  for (int o = 0; o < a; o++) {
    kolor[o] = 0;
  }
  int iterator = 0;

  int warunek = 0;
  //  int iterator2 = 0;

  while (warunek < a) {
    int iterator2 = 0;
    int wielkosc_stosu = 0;
    for (int u = 0; u < a; u++) {
      wielkosc_stosu += stab[iterator][u];
    }

    int stos[wielkosc_stosu];
    // kolor[0] = 1;
    for (int w = 0; w < a; w++) {
      if (stab[iterator][w] > 0) {
        stos[iterator2] = w;
        iterator2++;
      }
    }
    for (int l = 0; l < wielkosc_stosu; l++) {
      cout << stos[l] << "_";
    }
    cout << endl;
    int r = 0;
    // int be = 0;
    int kol = 1;
  nie:
    int be = 0;
    while (r < 1) {
      //      if (stab[iterator][stos[be]] == kol)
      if (kolor[stos[be]] == kol) {
        kol++;
        goto nie;
      }
      be++;
      if (be == wielkosc_stosu) {

        kolor[iterator] = kol;
        r++;
      }
    }
    iterator++;
    warunek++;
  }
  for (int v = 0; v < a; v++) {
    cout << "wierzcholek " << tabe[v] << " ma kolor numer " << kolor[v] << endl;
  }
  cout << endl;
  for (int wu = 0; wu < a; wu++) {
    graf << tabe[wu] << "[style=\"filled\" fillcolor=\"" << kolorki[kolor[wu]]
         << "\"]" << endl;
  }
  //  graf << "\"]" << endl;
  graf << "}";
  graf.close();
}
void lustereczko_powiedz_przecie(int b, int a) {
  if (b == a) {
    cout << "Graf jest ojlerowski!" << endl << endl << endl << endl;
  } else {
    cout << "Graf nie jest ojlerowski!" << endl << endl << endl << endl;
  }
}
