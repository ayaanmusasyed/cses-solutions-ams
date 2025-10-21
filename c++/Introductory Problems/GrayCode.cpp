/**
 * A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
 * Your task is to create a Gray code for a given length n.
*/

#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

// From GeeksForGeeks (https://www.geeksforgeeks.org/dsa/binary-representation-of-a-given-number/)
string getBinaryRep(unsigned long long n, int t) {

    string ans = "";
    
    for (int k = t - 1; k >= 0; --k)
        ans += ((n >> k) & 1ULL) ? '1' : '0';

    return ans;
}

int main() { 
    // Main Idea, if we do i XOR (i << 1) we will always get the next one that differs by one bit 
    int n; 
    cin >> n;

    unsigned long long total;
    total = 1ULL << n;

    for (unsigned long long i = 0; i < total; i++) { 
        unsigned long long ans = i ^ (i >> 1); 
        cout << getBinaryRep(ans, n) << "\n";
    }

    return 0;
}