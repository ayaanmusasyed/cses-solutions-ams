/**
 * Consider a money system consisting of n coins. Each coin has a positive integer value. 
 * Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
*/

#include <iostream>
#include <vector>
using namespace std;

int main (){
    int n; 
    int x; 
    cin >> n >> x; 

    vector<int> coins; 
    int temp;
    for (int j = 0; j < n; j++) { 
        cin >> temp; 
        coins.push_back(temp);
    }

    // Bounded Knapsack - iterate the coins first then val 
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    const int m = 1000000007;
    for (int c = 0; c < n; c++) { 
        for (int i = 1; i <= x; i++) {
            if (coins[c] <= i) { 
                dp[i] += dp[i - coins[c]];
                dp[i] = dp[i] % m;
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}