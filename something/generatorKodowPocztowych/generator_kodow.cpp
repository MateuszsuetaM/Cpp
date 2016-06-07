#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  system("clear");
  string start, koniec;
  cout << "Podaj adresy " << endl;
  cin >> start;
  cin >> koniec;
  string ps = start.substr(0, 2);
  int pss = atoi(ps.c_str());
  string ds = start.substr(3, 3);
  int dss = atoi(ds.c_str());
  string pk = koniec.substr(0, 2);
  int pkk = atoi(pk.c_str());
  string dk = koniec.substr(3, 3);
  int dkk = atoi(dk.c_str());
  int end = 1000;
  for (pss; pss <= pkk; pss++) {
    if (pss == pkk) {
      end = dkk;
      dss = 000;
    }
    for (dss += 1; dss < end; dss++) {

      cout << pss << "-" << setfill('0') << setw(3) << dss << endl;
    }
  }
}
