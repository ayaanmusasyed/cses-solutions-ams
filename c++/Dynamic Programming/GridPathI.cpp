/**
 * Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
 * Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() { 
    int n; 
    cin >> n;

    vector<vector<long long>> grid(n, vector<long long>(n,0LL));
    // Check for traps
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            char x; 
            cin >> x; 
            if (x == '*') {
                grid[i][j] = -1;
            }
        }
    }
    long long M = 1000000007;
    // Check start and end 
    if (grid[0][0] != -1) {
        grid[0][0] = 1;
    }

    // Fill top row and col first 
    for (int j = 1; j < n; j++) {
        if (grid[0][j] != -1) { 
            if (grid[0][j - 1] != -1) { 
                grid[0][j] = grid[0][j - 1];
            } else { 
                grid[0][j] = 0; 
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (grid[i][0] != -1) { 
            if (grid[i - 1][0] != -1) { 
                grid[i][0] = grid[i - 1][0];
            } else { 
                grid[i][0] = 0; 
            }
        }
    }

    for (int i = 1; i < n; i++) { 
        for (int j = 1; j < n; j++) {
            if (grid[i][j] != -1) {
                long long from_up = max(0LL, grid[i - 1][j]);
                long long from_left = max(0LL, grid[i][j - 1]);
                grid[i][j] = (from_up + from_left) % M;
            }
        }
    }

    cout << max(0LL,grid[n - 1][n - 1]) % M << "\n";
    return 0;

}