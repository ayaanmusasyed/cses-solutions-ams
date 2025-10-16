/**
 * Consider a money system consisting of n coins. 
 * Each coin has a positive integer value. 
 * Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() { 
    int n; 
    int x; 
    cin >> n >> x; 

    vector<int> coins; 
    int temp;
    for (int j = 0; j < n; j++) { 
        cin >> temp; 
        coins.push_back(temp);
    }

    // Let dp be the min ways to get to target with coins
    vector<int> dp(x + 1, 1000000000);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) { 
        for (int c = 0; c < n; c++) { 
            if (coins[c] <= i) { 
                dp[i] = min(dp[i], dp[i - coins[c]] + 1);
            }
        }
    }

    if (dp[x] == 1000000000) { 
        cout << -1 << "\n";
    } else { 
        cout << dp[x] << "\n";
    }
    return 0;
}