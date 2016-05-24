#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ofstream graf;
  graf.open("/home/mateusz/C++/graf.dot");
  graf << "graph graf{\n";
  int a, j, u, s;
  // int h = 0;
  int o = 0;
  cout << "Podaj ilosc wierzcholkow grafu." << endl;
  cin >> a;
  if (a == 0) {
    cout << "Szanowna Pani, ja nie mam tu nic do roboty :)";
  }
  int tab[a];
  int stab[a][a];
  // for (int it = 0; it < a; it++) {
  //   tab[it] = 0;
  //   for (int ir = 0; ir < a; ir++) {
  //     stab[ir][it] = 0;
  //   }
  // }
  char tabe[27] = "abcdefghijklmnopqrstuvwxyz";
  // for (int i = 0; i < a; i++) {
  //   int w = i + 1;
  //   for (j = w; j < a; j++) {
  //     cout << "Ile jest polaczen miedzy wierzcholkami " << tabe[i] << " i "
  //          << tabe[j] << "? (jesli zadne to wpisz 0)" << endl;
  //
  //     cin >> u;
  //     tab[i] = tab[i] + u;
  //     tab[j] = tab[j] + u;
  //
  //     if (u > 0) {
  //       // stab[i][i]++;
  //       stab[j][i]++;
  //       stab[i][j]++;
  //       while (u > 0) {
  //         graf << tabe[i] << " -- " << tabe[j] << ";\n";
  //         u--;
  //       }
  //     }
  //   }
  //   graf << "\n";
  // }
  graf << "}";
  graf.close();
  // for (int it = 0; it < a; it++) { // wyswietlanie macierzy
  //   for (int ir = 0; ir < a; ir++) {
  //     cout << stab[ir][it];
  //   }
  //   cout << endl;
  // }
  // for (int g = 0; g < a; g++) {
  //   int as = tab[g];
  //   if (as % 2 == 0) {
  //   } else {
  //
  //     cout << "Podany graf nie jest eulerowski." << endl;
  //     return 0;
  //   }
  // }
  int stos[a];
  int odwiedzone[a];
// for (int r = 0; r < a; r++) {
//     stos[r] = 0;
//     odwiedzone[r] = 0;
//   }
  //-----------------------------------------------------------------
  int sto = 1;
  odwiedzone[0] = 1;
  stos[0] = 0;
  // for (int n = 0; n < a; n++) { // sprawdzanie pierwszego wiersza
  //
  //   if (stab[0][n] > 0) {
  //     stos[sto] = n;
  //     sto++;
  //     odwiedzone[n] = 1;
  //   }
  // }
  //////////////////////////////////////////
  int warunek = 0;
  int z = 1;
  int x;
  int jest = 0;
  int do_warunku = 0;
  // int nie = 0;


  // while (warunek < 1) {
  //
  //   int tak = 0;
  //   x = stos[z];
  //   for (int y = 0; y < a; y++) { // sprawdzanie linii
  //     jest = 0;
  //     if (stab[x][y] > 0) {
  //       do_warunku++;
  //       for (int s = 0; s < a; s++) { // sprawdzanie czy "y" jest na stosie
  //         if (stos[s] == y) {
  //           tak++;
  //           jest++;
  //           break;
  //         }
  //       }
  //       /////////////////////////////////
  //       if (jest > 0) {
  //       } else { ///////////////////////jesli "y" nie jest na stosie to dodaje
  //         ///////////////////////////// je do stosu i do odwiedzonych
  //         stos[sto] = y;
  //         odwiedzone[y] = 1;
  //         sto++;
  //       }
  //     }
  //     for (int l = 0; l < 5; l++) { ///////sprawdzanie odwiedzonych
  //       o += odwiedzone[l];
  //     }
  //
  //     if (o == a) {
  //       warunek = 1;
  //     } else {
  //       o = 0;
  //     }
  //   }
  //   if (do_warunku == tak) {
  //     warunek = 1;
  //   }
  //   do_warunku = 0;
  //   tak = 0;
  //   jest = 0;
  //   z++;
  // }

  int b = 0;
  for (int c = 0; c < a; c++) {
    b += odwiedzone[c];
  }
  // cout << "Odwiedzone: ";
  // for (int c = 0; c < a; c++) {
  //   cout << odwiedzone[c] << ", ";
  // }
  // cout << "Stos: ";
  // for (int c = 0; c < a; c++) {
  //   cout << stos[c] << ", ";
  // }


  if (b == a) {
    cout << "Graf jest ojlerowski!" << endl << endl << endl << endl;
  } else {
    cout << "Graf nie jest eulerowski!" << endl << endl << endl << endl;
  }



  // s = tab[0];
  // for (int u = 0; u < a; u++) {
  //   cout << "Wierzcholek " << tabe[u] << " ma wage " << tab[u] << endl;
  //   if (tab[u] > s) {
  //     s = tab[u];
  //   }
  // }
  // cout << "Stopien grafu wynosi: " << s << endl;
}
