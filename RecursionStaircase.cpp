#include <iostream>
#include <vector>
using namespace std;

vector<int> table(36, 0);

int StaircaseRec(int height) {
  if(!table[height - 1])
    table[height - 1] = StaircaseRec(height - 1) + StaircaseRec(height - 2) + StaircaseRec(height - 3);
  return table[height - 1];
}

int main() {
  table[0] = 1;
  table[1] = 2;
  table[2] = 4;
  int s;
  cin >> s;
  for(int a0 = 0; a0 < s; a0++){
    int n;
    cin >> n;
    cout << StaircaseRec(n) << endl;
  }
  return 0;
}
