#include <bits/stdc++.h>

using namespace std;

int temp = 0;
int diff = 0;
double median = 0;

class compareMin {
  public:
  bool operator() (int a, int b){
    return !(a < b);
  }
};

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, compareMin> minHeap;

int main(){
  int n;
  cin >> n;
  for(int a_i = 0;a_i < n;){
    a_i++;
    cin >> temp;
    if(a_i == 1 || a_i == 2) {
      if(a_i == 1)
        maxHeap.push(temp);
      else {
        minHeap.push(temp);
        int a = maxHeap.top();
        int b = minHeap.top();
        if(b < a) {
          maxHeap.pop();
          minHeap.pop();
          maxHeap.push(b);
          minHeap.push(a);
        }
      }
    }
    else if(temp < maxHeap.top())
      maxHeap.push(temp);
    else
      minHeap.push(temp);

    diff = minHeap.size() - maxHeap.size();
    if( diff >= 2) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
    else if(diff <= -2) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }

    if(a_i % 2)
      median = (minHeap.size() < maxHeap.size()) ? maxHeap.top() : minHeap.top();
    else
      median = (maxHeap.top() + minHeap.top()) / 2.0;
    cout << fixed << setprecision(1) << median << endl;
  }
  return 0;
}
