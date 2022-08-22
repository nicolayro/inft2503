//-------------------------------------------------------------------
//
// toerpot.cpp
//
// Programmet skriver toerpotenser til fil.
// Alle toerpotenser mindre enn halvparten av
// maksimalverdien til "long int" skrives ut.
//
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  const char filename[] = "toerpot.dat";
  ofstream file;
  file.open(filename);
  if (!file) {
    cout << "Feil ved åpning av utfil." << endl;
    exit(EXIT_FAILURE);
  }
  long int product = 1L;
  int exponent = 0;
  while (product <= LONG_MAX / 2L) {
    exponent++;
    product *= 2L;
    file << "2 opphøyd i " << setw(4) << exponent << " er "
         << product << endl;
  }
  file.close();
}

/* Filen ser slik ut:
2 opphøyd i    1 er 2
2 opphøyd i    2 er 4
2 opphøyd i    3 er 8
...
2 opphøyd i   28 er 268435456
2 opphøyd i   29 er 536870912
2 opphøyd i   30 er 1073741824
*/
