/**
 * Your task is to calculate the number of bit strings of length n.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){ 
    int n; 
    cin >> n;

    int m = 1000000007;

    int res = 1; 
    for (int i = 1; i <= n; i++) { 
        if (res == 0) { 
            res = 1;
        } else { 
            res *= 2;
        }

        res = res % m;
    }
    cout << res << "\n";
    return 0; 
}