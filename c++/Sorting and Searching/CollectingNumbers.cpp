/**
 * You are given an array that contains each number between 1 \dots n exactly once.
 * Your task is to collect the numbers from 1 to n in increasing order.
 * On each round, you go through the array from left to right and collect as many numbers as possible.
 * 
 * What will be the total number of rounds?
*/

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

int main() { 
    int n; 
    cin >> n; 

    // For all x, if x + 1 is after x, can be picked up tgt 
    // Else, 2 seperate trips 
    vector<int> idx(n + 1,0); 
    for (int i = 1; i <= n; i++) { 
        int x; 
        cin >> x; 
        idx[x] = i;
    }

    int res = 1; 
    for (int i = 1; i < n; i++) { 
        if (idx[i + 1] < idx[i]) { 
            res += 1;
        }
    }

    cout << res << "\n";
    return 0; 
}