#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main() {
  clock_t start;
  clock_t stop;
  int n;
  cout << "podaj wielkosc tablicy" << endl;
  cin >> 10;
  int *w;
  int tab[n];
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  // cout<<"ile elementow jest w liscie?"<<endl;
  w = tab;
  for (int j = 0; j < n; j++) {
    cout << (*w + 50);
    w++;
  }
}
