/**
 * There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
 * Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x.
 * 
 * You know the weight of every child.
 * 
 * What is the minimum number of gondolas needed for the children?
*/

#include <iostream> 
#include <vector> 
#include <cmath>
#include <algorithm>
using namespace std; 

int main() {
    int n; 
    unsigned long long x; 
    cin >> n >> x; 

    vector<unsigned long long> weights; 
    unsigned long long y = 0ULL; 
    for (int i = 0; i < n; i++) { 
        cin >> y; 
        weights.push_back(y);
    }
    sort(weights.begin(), weights.end());

    unsigned long long num_buckets = 0ULL; 

    int j = 0; 
    int k = n - 1;
    // Idea -> pair lightest w/ heaviest 
    while (j <= k) {
        if (weights[j] + weights[k] <= x) { 
            j += 1; 
        }
        k -= 1; 
        num_buckets += 1;
    }

    cout << num_buckets << "\n";
    return 0; 
}