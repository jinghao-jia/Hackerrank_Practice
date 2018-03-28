#include <iostream>
#include <chrono>

using namespace std;

void algc(long n) {
  if (n == 1)
    return;
  algc(n - 1);
  algc(n - 1);
}

int main(void) {

  for(int i = 1; i < 100000; i++) {
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    algc(i);
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    cout << i << " "<< d.count() << endl;
  }
}
