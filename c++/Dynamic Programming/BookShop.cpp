/**
 * You are in a book shop which sells n different books. 
 * You know the price and number of pages of each book.
 * 
 * You have decided that the total price of your purchases will be at most x. 
 * What is the maximum number of pages you can buy? You can buy each book at most once.
*/

#include <iostream>
#include <vector>
using namespace std; 

int main() { 
    int n; 
    int x; 
    cin >> n >> x; 

    vector<int> prices; 
    for (int i = 0; i < n; i++) { 
        int x; 
        cin >> x; 
        prices.push_back(x); 
    }

    vector<int> pages; 
    for (int i = 0; i < n; i++) { 
        int x; 
        cin >> x; 
        pages.push_back(x);
    }

    vector<long> dp(x + 1, 0);

    // Initialize first row 
    for (int p = 1; p <= x; p++) { 
        if (p >= prices[0]) { 
            dp[p] = pages[0];
        }
        // cout << "Row " << 0 << " Col " << p << ": " << dp[0][p] << "\n";
    }

    for (int i = 1; i < n; i++) { 
        int curr_pages = pages[i];
        int curr_price = prices[i];
        for (int p = x; p >= curr_price; p--) { 
            dp[p] = max(dp[p], dp[p - curr_price] + curr_pages);
            // cout << "Row " << i << " Col " << p << ": " << dp[i][p] << "\n";
        }
    }

    cout << dp[x] << "\n";
    return 0;
}