/**
 * Your task is to count for k=1,2,...n, the number of ways two knights can be placed on 
 * a k X k chessboard so that they do not attack each other.
*/

#include <iostream>
using namespace std; 

int main(){ 
    int k; 
    cin >> k; 

    for (int i = 1; i <= k; i++) { 
        unsigned long long res = 0ULL; 
        // Base Case: if i == 1, then there is 0 ways 
        if (i == 1) { 
            res = 0ULL;
        }
        else {
            // Total Squares
            unsigned long long n = i * i;

            // Total ways to not attack = Total ways - total ways w/ attacking 
            unsigned long long total_ways = (n*(n - 1))/2; // divide by two as knights are identical 

            // Total ways attacking = 2 * Ways to place (2x3) rect in nxn * 2 (first 2 is by symmetry; 2nd is for two orientations of knights)
            unsigned long long attack = 2 * 2 * (i - 2) * (i - 1);

            res = total_ways - attack;
        }

        cout << res << "\n";
    }

    return 0;
}