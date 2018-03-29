#include <cmath>
#include <iostream>
using namespace std;

inline bool isPrime(long num) {
  if(num <= 1 || (num > 2 && num % 2 == 0))
    return false;
  for(long i = 3; i <= (long)sqrt(num) + 1; i+=2)
    if(!(num % i))
      return false;
  return true;
}

int main() {
  int p;
  cin >> p;
  for(int a0 = 0; a0 < p; a0++){
    long n;
    cin >> n;
    cout << (isPrime(n) ? "Prime" : "Not prime") << endl;
  }
  return 0;
}
