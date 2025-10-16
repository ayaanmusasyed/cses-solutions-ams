/**
 * You are given an array of n integers. You want to modify the array so that it is increasing, 
 * i.e., every element is at least as large as the previous element.
 * On each move, you may increase the value of any element by one. 
 * 
 * What is the minimum number of moves required?
*/

#include <iostream>
#include <vector>
using namespace std; 

int main() { 
    unsigned long long n; 
    cin >> n; 

    vector<unsigned long long> nums(n,0);
    unsigned long long x; 
    for (int i = 0; i < n; i++) { 
        cin >> x; 
        nums[i] = x; 
    }

    unsigned long long res = 0ULL;
    for (int j = 1; j < n; j++) { 
        if (nums[j] < nums[j - 1]) { 
            res += nums[j - 1] - nums[j]; 
            nums[j] = nums[j - 1];
        }
    }

    cout << res << "\n";
    return 0;

}