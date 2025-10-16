#include <iostream>
using namespace std;

int main() {
    // The following is for optimization for compiling 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    unsigned long long n; 
    std::cin >> n;

    unsigned long long S = 0ULL; // true sum 
    S = (n*(n + 1))/2;

    unsigned long long sum = 0ULL, x;
    for (int i = 1; i < n; i++) { 
        cin >> x; 
        sum += x;
    } 

    unsigned long long res = S - sum; 
    cout << res << "\n";
    return 0;
}