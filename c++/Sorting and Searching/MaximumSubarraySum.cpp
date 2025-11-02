/**
 * Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() { 
    int n;
    cin >> n; 

    vector<long long> nums;
    long long x; 
    for (int i = 0; i < n; i++) { 
        cin >> x; 
        nums.push_back(x);
    }

    // Using Kadane's algorithm - O(n)
    /**
     * For every element, we an either (i) Extend the previous sum or (ii) Start a new subarray 
    */

    long long res = 0LL;
    long long maxEnding = 0LL;

    for (int i = 0; i < n; i++) { 
        if (i == 0) { 
            res = nums[i];
            maxEnding = nums[i];
        }
        else { 
            maxEnding = max(maxEnding + nums[i], nums[i]);
            res = max(maxEnding, res);
        }
    }

    cout << res << "\n";
    return 0;
}