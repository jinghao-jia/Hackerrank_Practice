/* We use congruent modolo, (a + b) % k != 0 means (a % k + b % k) % k != 0
Thus we have several ways to divide the the set into subsets: c % k = 1 vs c % k = k - 1
and add the larger set to the count.
Edge cases:
When c % k = k / 2 we can only add one number from this set
the same works for c % k = 0
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector <int> r (k);
    for(int i = 0; i < n; i++) {
        long temp;
        cin >> temp;
        r[temp % k]++;
    }
    long count = 0;
    for(int i = 1; i <= k / 2; i++) {
        if(k == i * 2)
            count += 1;
        else
            count += r[i] > r[k - i] ? r[i] : r[k - i];
    }
    if(r[0])
        count++;

    cout << count;

    return 0;
}
