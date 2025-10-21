/**
 * You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
*/

#include <iostream>
#include <unordered_set>
using namespace std; 

int main(){ 

    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int n; 
    cin >> n; 

    unsigned long long x; 
    unordered_set<unsigned long long> distinct; 
    distinct.reserve(n*2);
    distinct.max_load_factor(0.7f);
    
    for (int i = 0; i < n; i++){ 
        cin >> x; 
        distinct.insert(x); 
    }

    cout << distinct.size() << "\n";
    return 0; 
}