/**
 * You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
 * Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
*/

#include <iostream> 
#include <vector> 
using namespace std; 

int main() { 
    int n;
    int m;  
    cin >> n >> m;

    /**
     * Main Idea: Let dp[i][j] be the number of ways to fill up to index i, where arr[i] = j
    */
    vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(m + 1, 0ULL));
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        arr[i] = x;
    }

    // DP Formula: If arr[i] = 0 and arr[i - 1] = x, then dp[i][v] = dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]

    // Initialize first row
    if (arr[0] == 0) { 
        for (int i = 1; i <= m; i++) { 
            dp[0][i] = 1;
        }
    } else { 
        dp[0][arr[0]] = 1;
    }
    long long M = 1000000007;
    for (int i = 1; i < n; i++) { 
        for (int j = 1; j <= m; j++) {
            // If arr[i] is not set
            if (arr[i] == 0) { 
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                if (j < m) { 
                    dp[i][j] += + dp[i - 1][j + 1];
                }
            }
            else { 
                if (j == arr[i]) { 
                    dp[i][arr[i]] = dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]];
                    if (j < m) { 
                        dp[i][j] += + dp[i - 1][j + 1];
                    }
                }
            }

            dp[i][j] = dp[i][j] % M;
        }
    }

    unsigned long long res = 0ULL; 
    for (int k = 0; k <= m; k++) { 
        res += dp[n - 1][k];
        res = res % M;
    }

    cout << res << "\n";
    return 0; 
}