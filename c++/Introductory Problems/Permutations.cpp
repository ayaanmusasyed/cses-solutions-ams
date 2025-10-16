/**
 * A permutation of integers 1,2,...,n is called beautiful if there are no adjacent elements whose difference is 1.
 * Given n, construct a beautiful permutation if such a permutation exists.
*/

#include <vector> 
#include <iostream>
using namespace std;

int main() { 
    unsigned long long n; 
    cin >> n; 

    if (n == 1) { 
        cout << n << "\n";
    }
    else if (n == 2 or n == 3) { 
        cout << "NO SOLUTION" << "\n";
    }
    else { 
        for (int i = 2; i <= n; i += 2) { 
            cout << i << " ";
        }
        for (int j = 1; j <= n; j += 2) { 
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;

}