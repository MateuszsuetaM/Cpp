#include <curses.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class samochod {
public:
  string marka;
  string model;
  int rocznik;
  void wypelnij() {
    cout << "Jakiej marki jest twa gablota?" << endl;
    cin >> marka;
    cout << "Jaki to model?" << endl;
    cin >> model;
    cout << "Jaki rocznik?" << endl;
    cin >> rocznik;
  }
  void elo() {
    cout << "Samochodzik marki " << marka << ", model " << marka << " " << model
         << ", " << rocznik << endl;
  }
};

int main() {
  samochod s1;
  s1.wypelnij();
  s1.elo();
  return 0;
}
