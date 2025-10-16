/**
 * Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
 * Each throw produces an outcome between 1 and  6.
*/

#include <iostream>
#include <vector> 
#include <cmath>
using namespace std; 

int main() { 
    unsigned long long n = 0ULL; 
    cin >> n; 

    vector<unsigned long long> dp(n + 1,0); 
    dp[0] = 1;

    vector<int> dice = {1,2,3,4,5,6};
    const int m = 1000000007;
    for (unsigned long long i = 1; i <= n; i++) { 
        for (int d : dice) { 
            if (i >= d) { 
                dp[i] += dp[i - d];
                dp[i] = static_cast<unsigned long long>(dp[i] % m);
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}