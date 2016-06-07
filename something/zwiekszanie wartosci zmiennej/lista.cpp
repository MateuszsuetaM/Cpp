#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int koniec = 5;
  float wynik = 2;
  for (wynik; wynik <= koniec; wynik += 0.5) {
    cout << fixed << setprecision(1) << wynik << endl;
  }
}
