/* looks for least row and largest column*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    const double min_row = floor(sqrt(s.size()));
    const double max_col = ceil(sqrt(s.size()));
    double row = min_row;
    while(true) {
        if(row * ceil(s.size()/row) >= (double)s.size() && ceil(s.size()/row) <= max_col)
            break;
        row++;
    }
    double col = ceil(s.size()/row);
    vector<string> matrix((int) row);
    for(int i = 0; i < row; i++) {
        matrix[i] = s.substr(0, col);
        s.erase(0, col);
        //cout << matrix[i].size() << endl;
    }
    for(int i = 0; i < col; i++) {
        int count = 0;
        for(int j = 0; j < row; j++) {
            if(i >= matrix[j].size())
                continue;
            cout << matrix[j][i];
            //count++;
        }
        if(i != col - 1)
          cout << " ";
        //cout << count << endl;
    }
    return 0;
}
