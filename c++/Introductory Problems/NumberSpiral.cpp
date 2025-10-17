/**
 * A number spiral is an infinite grid whose upper-left square has number 1.
 * eg 4 x 4 is [[1,2,9,10],[4,3,8,11],[5,6,7,12],[16,5,14,13]]
 * Find number at row y col x
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){ 
    int t; // number of tests 
    cin >> t; 

    for (int i = 0; i < t; i++) { 
        // Along diagonal, a(n + 1) = a(n) + 2n --> a(n) = n^2 - n + 1
        // Let n = max(y,x) --> we can say that (n - 1)^2 + 1= n^2 - 2n + 2 <= (y,x) <= n^2
        unsigned long long n = 0ULL; 
        unsigned long long y = 0ULL; 
        unsigned long long x = 0ULL; 
        cin >> y >> x; 
        n = max(y, x);

        unsigned long long res = n*n - n + 1; 
        // Case 1: n is even --> increasing from down to left 
        if (n % 2 == 0) { 
            // Case a: Decrease row --> decrease number 
            if (y < n)  { 
                res -= (n - y);
            }
            // Case b: Decrease col --> increase number 
            else if (x < n) { 
                res += (n - x);
            }
        }
        // Case 2: n is odd --> increasing from right to up
        else { 
            // Case a: Decrease row --> increase number
            if (y < n) { 
                res += (n - y);
            }
            // Case b: Decrease col --> decrease number 
            else if (x < n) { 
                res -= (n - x);
            }
        }

        cout << res << "\n";

    }

    return 0;
}