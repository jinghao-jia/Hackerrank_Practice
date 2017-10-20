#include <iostream>

using namespace std;

class Integer2{
  int v;
public:
  Integer2();
  Integer2(int magicNumber);
  int getValue();

};
Integer2::Integer2(): v(0) {};

Integer2::Integer2(int magicNumber): v(magicNumber) {}
int Integer2::getValue() {
  return v;
}

class Swap {
public:
  static void swap (Integer2 x, Integer2 y);
};

void Swap::swap (Integer2 x, Integer2 y) {
  Integer2 temp = Integer2(x.getValue());
  x = Integer2(y.getValue());
  y = Integer2(temp.getValue());
}
int main(void) {
  Integer2 a = Integer2(1);
  Integer2 b = Integer2(2);
  swap(a, b);
  cout << "a=" << a.getValue() << " b=" << b.getValue() << endl;
}
