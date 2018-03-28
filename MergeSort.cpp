#include <iostream>
#include <vector>

using namespace std;

vector<long> original;

void MergeSub(vector<long> &original, int start, int mid, int end) {
  vector<long> temp;
  int i = start, j = mid;
  while(i < mid || j < end) {
    if(i < mid && j < end) {
      if(original[i] < original[j]) {
        temp.push_back(original[i]);
        i++;
      }
      else {
        temp.push_back(original[j]);
        j++;
      }
    }
    else if(i >= mid) {
      temp.push_back(original[j]);
      j++;
    }
    else if(j >= end) {
      temp.push_back(original[i]);
      i++;
    }
  }
  for(int i = 0; i < end - start; i++) {
    original[i + start] = temp[i];
  }
}

void MergeSort(vector<long> &original, int start, int end) {
  if(end - start <= 1)
    return;

  int mid = (start + end) / 2;

  MergeSort(original, start, mid);
  MergeSort(original, mid, end);

  MergeSub(original, start, mid, end);
}

int main(int argc, char * const * argv) {
  for(int i = 1; i < argc; i++) {
    original.push_back(stol(argv[i]));
  }
  MergeSort(original, 0, original.size());
  for(int i = 0; i < original.size(); i++) {
    cout << original[i] << " ";
  }
  cout << endl;
}
