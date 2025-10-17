/**
 * You have two coin piles containing a and b coins. 
 * On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
 * Your task is to efficiently find out if you can empty both the piles.
*/

#include <iostream>
#include <cmath>
using namespace std; 

int main() { 
    int t; // Number of tests 
    cin >> t; 

    for (int i = 0; i < t; i++) { 
        unsigned long long a = 0ULL; 
        unsigned long long b = 0ULL;
        cin >> a >> b;

        unsigned long long min_a = ceil(a/2);
        unsigned long long max_a = a; 

        unsigned long long min_b = ceil(b/2);
        unsigned long long max_b = b;

        if (min_a > max_b || min_b > max_a) { 
            cout << "NO" << "\n";
        } 
        else if ((a + b) % 3 != 0) { 
            cout << "NO" << "\n";
        }
        else {
           cout << "YES" << "\n";
        }
    }

    return 0;
}