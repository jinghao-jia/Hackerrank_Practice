/* Check if the number of balls in each container matches the number of balls
   of each type
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > M(n,vector<int>(n));
        vector <int> type (n);
        list <int> typel;
        vector <int> container (n);
        list <int> containerl;
        for(int M_i = 0;M_i < n;M_i++){
           for(int M_j = 0;M_j < n;M_j++){
               int temp;
              cin >> temp;
               type[M_i] += temp;
               container[M_j] += temp;
           }
        }
        for(int i = 0; i < n; i++) {
            typel.push_back(type[i]);
            containerl.push_back(container[i]);
        }
        typel.sort();
        containerl.sort();
        int flag = 1;
        for(auto it = typel.begin(), it2 = containerl.begin(); it != typel.end(); it++, it2++) {
            if(*it != *it2) {
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
        // your code goes here
    }
    return 0;
}
