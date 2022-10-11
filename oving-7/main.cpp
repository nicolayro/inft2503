#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

  cout << "Oppgave 7:" << endl;
  cout << "a)" << endl;
  print("a = ", a);
  print("5 - a = ", 5 - a);
  print("a - 5 = ", a - 5);

  cout << "b)" << endl;
  print("a = ", 5 - 3 - a - 7 - b);
  cout << "Blir tolket slik:" << endl;
  cout << "(((5 - 3) - a) - 7) - b" << endl;
  cout << "Operasjoner: " << endl;
  cout << "5 - 3" << endl;
  cout << "2 - fraction1 (=fraction3)" << endl;
  cout << "fraction3 - 7 (=fraction4)" << endl;
  cout << "fraction4 - fraction2 (=fraction5)" << endl;
  cout << "Med andre ord brukes alle tre implementasjoner av '-' operatoren." << endl;
}

