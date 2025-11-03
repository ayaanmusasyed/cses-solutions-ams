/**
 * You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
*/

#include <iostream> 
#include <algorithm> 
using namespace std; 

int main() { 
    int n; 
    cin >> n; 

    vector<long long> coins; 
    for (int i = 0; i < n; i++) { 
        long long x; 
        cin >> x; 
        
        coins.push_back(x); 
    }

    sort(coins.begin(), coins.end()); 
    long long val = 1LL;

    for (auto c: coins) { 
        if (c > val) { 
            break;
        } else { 
            val += c;
        }
    }

    cout << val << "\n";
    return 0; 
}