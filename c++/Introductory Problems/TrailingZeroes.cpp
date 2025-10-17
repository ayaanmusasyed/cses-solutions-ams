/**
 * Your task is to calculate the number of trailing zeros in the factorial n!.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() { 
    int n; 
    cin >> n;

    // tldr -> just return n//5 + n//25 + ...

    int res = 0;
    int temp = 5;

    while (temp <= n) { 
        res += floor(n/temp);
        temp *= 5;
    }

    cout << res << "\n";
    return 0;
}