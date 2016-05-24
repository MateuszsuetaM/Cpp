#include <fstream>
#include <iostream>

using namespace std;

class Pytanie {
public:
  string tresc;
  string a, b, c, d;
  int nr_pytania;
  string odpowiedz;
  string poprawna;
  int punkt;

  void wczytaj();
  void zadaj();
  void sprawdz();
};

int main() {}
