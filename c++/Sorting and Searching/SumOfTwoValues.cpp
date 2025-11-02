/**
 * You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
*/

#include <iostream> 
#include <unordered_map>
using namespace std; 

int main() { 
    int n;
    long long x;  
    cin >> n >> x;

    unordered_map<long long, int> f; 
    long long curr;
    long long target;
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < n; i++) { 
        cin >> curr; 
        if (curr < x) { 
            target = x - curr; 
            auto it = f.find(target);
            if (it != f.end()) { 
                p1 = it->second;
                p2 = i + 1;
            } else {
                f.insert({curr, i + 1});
            }
        }
    }

    if (p1 == 0) { 
        cout << "IMPOSSIBLE" <<"\n";
    } else {
        cout << p1 << " " << p2 << "\n";
    }

    return 0;
}