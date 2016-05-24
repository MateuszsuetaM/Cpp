#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int a, w, s, x, b, q, jest;
int o = 0, do_warunku = 0, warunek = 0;
int z = 0, sto = 1;
char tabe[27] = "abcdefghijklmnopqrstuvwxyz";

//------------------------------------------------------------------funkcje
void wypelnianie_tablicy(int *tab, int a, int *stos, int *odwiedzone,
                         int **stab);
void sprawdzanie_polaczen(int *tab, int a, int **stab);
void wyswietlanie_macierzy(int a, int **stab);
void sprawdzanie_parzystosci_wierzcholkow(int *tab);
void DFS(int x, int *stos, int jest, int do_warunku, int *odwiedzone, int sto,
         string test, int z, int o, int **stab);
void lustereczko_powiedz_przecie(int b, int a);
//------------------------------------------------------------------main
int main() {

  cout << "Podaj ilosc wierzcholkow grafu." << endl;
  cin >> a;
  int stos[a];

  int odwiedzone[a];

  if (a == 0) {
    cout << "Szanowna Pani, ja nie mam tu nic do roboty :)";
  }
  int tab[a];
  int **stab = new int *[a];
  for (int i = 0; i < a; i++)
    stab[i] = new int[a];

  wypelnianie_tablicy(tab, a, stos, odwiedzone, stab);
  sprawdzanie_polaczen(tab, a, stab);

  wyswietlanie_macierzy(a, stab);
  sprawdzanie_parzystosci_wierzcholkow(tab);
  if (q == 1) {
    cout << "Podany graf nie jest eulerowski" << endl;
    return 0;
  }
  cout << "Odwiedzone po 1 wierszu: ";
  for (int c = 0; c < a; c++) {
    cout << odwiedzone[c] << ", ";
  }
  cout << "Stos: ";
  for (int c = 0; c < a; c++) {
    cout << stos[c] << ", ";
  }
  DFS(x, stos, jest, do_warunku, odwiedzone, sto, test, z, o, stab);
  int b = 0;
  for (int c = 0; c < a; c++) {
    b += odwiedzone[c];
  }
  cout << "Odwiedzone: ";
  for (int c = 0; c < a; c++) {
    cout << odwiedzone[c] << ", ";
  }
  cout << "Stos: ";
  for (int c = 0; c < a; c++) {
    cout << stos[c] << ", ";
  }

  lustereczko_powiedz_przecie(b, a);
}
//----------------------------------------------------------ciała_funkcji
void wypelnianie_tablicy(int *tab, int a, int *stos, int *odwiedzone,
                         int **stab) {
  for (int it = 0; it < a; it++) {
    tab[it] = 0;
    stos[it] = 0;
    odwiedzone[it] = 0;
    for (int ir = 0; ir < a; ir++) {
      stab[ir][it] = 0;
    }
  }
  stos[0] = 0;
  odwiedzone[0] = 1;
}
void sprawdzanie_polaczen(int *tab, int a, int **stab) {
  // int sprawdzanie_polaczen(int *tab, int *tabe, int a, int **stab) {
  ofstream graf;
  graf.open("graf.dot");
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
  graf << "}";
  graf.close();
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
         string test, int z, int o, int **stab) {

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
      test = "tak";
      warunek = 1;
    }
    do_warunku = 0;
    tak = 0;
    jest = 0;
    z++;
  }
}
void lustereczko_powiedz_przecie(int b, int a) {
  if (b == a) {
    cout << "Graf jest ojlerowski!" << endl << endl << endl << endl;
  } else {
    cout << "Graf nie jest ojlerowski!" << endl << endl << endl << endl;
  }
}
