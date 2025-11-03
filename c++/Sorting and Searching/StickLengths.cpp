/**
 * There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
 * You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
 * What is the minimum total cost?
*/

#include <iostream> 
#include <vector>
#include <algorithm>
#include <climits>
using namespace std; 

int main() { 
    int n; 
    cin >> n; 

    vector<long long> sticks; 
    long long sum = 0LL; 
    for (int i = 0; i < n; i++) { 
        long long x; 
        cin >> x; 
        sum += x; 
        sticks.push_back(x);
    }

    // Take Median to minimise s.d 
    long long res = 0LL; 
    sort(sticks.begin(), sticks.end()); 
    long long median = sticks[n/2];
    for (int i = 0; i < n; i++) { 
        res += max(sticks[i] - median, median - sticks[i]);
    }

    cout << res << "\n";
    return 0; 

}