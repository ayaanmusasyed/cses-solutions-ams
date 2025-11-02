/**
 * You are given the arrival and leaving times of n customers in a restaurant.
 * What was the maximum number of customers in the restaurant at any time?
*/

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

int main() { 
    int n; 
    cin >> n;
    

    vector<long long> enter; 
    vector<long long> leave; 

    long long a; 
    long long b; 

    for (int i = 0; i < n; i++) { 
        cin >> a >> b; 
        enter.push_back(a);
        leave.push_back(b);
    }

    sort(enter.begin(), enter.end());
    sort(leave.begin(), leave.end());

    int i = 0;
    int j = 0;
    int res = 0; 
    int curr = 0; 
    while (i < n && j < n) {
        if (enter[i] <= leave[j]) { 
            curr += 1;
            i += 1;
        } else { 
            j += 1;
            curr -= 1;
        }

        if (res < curr) { 
            res = curr;
        }
    }

    cout << res << "\n";
    return 0;
}