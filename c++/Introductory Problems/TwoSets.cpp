/**
 * Your task is to divide the numbers 1,2,..,n into two sets of equal sum.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){ 
    unsigned long long n; 
    cin >> n; 

    // Check if sum is even 
    unsigned long long S = 1ULL * n * (n + 1)/2;

    if (S % 2 == 0) { 
        cout << "YES" << "\n";
        vector<unsigned long long> a; 
        vector<unsigned long long> b; 
        unsigned long long sum_a = 0ULL;
        unsigned long long target = S/2;
        for (unsigned long long i = n; i > 0; i -= 1) { 
            // Construct Sets
            if (i + sum_a <= target) { 
                a.push_back(i);
                sum_a += i;
            } else { 
                b.push_back(i);
            }
        }

        cout << a.size() << "\n";
        for (unsigned long long A: a) { 
            cout << A << " ";
        }
        cout << "\n";
        cout << b.size() << "\n";
        for (unsigned long long B: b) { 
            cout << B << " ";
        }
        cout << "\n";
    } else { 
        cout << "NO" << "\n";
    }
    return 0;
}