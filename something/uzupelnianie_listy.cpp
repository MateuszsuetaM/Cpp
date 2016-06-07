#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

int main() {
  system("clear");
  int a = 1;
  list<int> lista;
  list<int> brak;
  cout << "Podaj liczby rozdzielajac klawiszem \" enter \" Aby zakonczyc "
          "wprowadz \"0\" "
       << endl;
  int powinno = 1;
  while (a != 0) {
    cin >> a;
    lista.push_back(a);
    if (a != powinno) {
      for (powinno; powinno < a; powinno++) {
        brak.push_back(powinno);
      }
    }
    powinno++;
  }
  int m = 0;
  cout << endl << "W liscie brakuje:" << endl;
  for (list<int>::iterator j = brak.begin(); j != brak.end(); j++) {

    cout << *j << " ";
    m++;
  }
  cout << endl;
  if (m == 0) {
    cout << "Wszystko na miejscu :)" << endl;
  }
  lista.clear();
  brak.clear();
}
