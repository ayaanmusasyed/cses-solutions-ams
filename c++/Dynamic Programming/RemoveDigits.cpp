/**
 * You are given an integer n. On each step, you may subtract one of the digits from the number.
 * How many steps are required to make the number equal to 0?
*/

#include <iostream>
#include <cmath>
using namespace std; 

static int max_digit(int x) {
    int res = 0;
    int m = x;
    int d = 0;
    while (m > 0) {
        d = m % 10;
        res = max(res, d);
        m = floor((m - d) / 10);
    }

    return res;
}
int main(){ 
    int n; 
    cin >> n; 

    // Greedy Approach
    int steps = 0; 
    int digit; 
    while (n > 0) { 
        digit = max_digit(n);
        n -= digit;
        steps += 1;
    }

    cout << steps << "\n";
    return 0;

}