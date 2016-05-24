#include <cstdio>
#include <iostream>
using namespace std;

int wypelnij(int s, int **tab) {

  for (int w = 0; w < s; w++) {
    for (int i = 0; i < s; i++) {
      tab[w][i] = 0;
    }
  }
}

void wypisz(int s, int **tab) {
  for (int g = 0; g < s; g++) {
    for (int j = 0; j < s; j++) {
      cout << tab[g][j];
    }
    cout << endl;
  }
}

int main() {
  int s;
  int w = 0;
  cin >> s;

  int **tab = new int *[s];
  for (int i = 0; i < s; i++)
    tab[i] = new int[s];

  wypelnij(s, tab);
  wypisz(s, tab);

  return 0;
}
