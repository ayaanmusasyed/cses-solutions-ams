/**
 * In a movie festival n movies will be shown. 
 * You know the starting and ending time of each movie.
 * What is the maximum number of movies you can watch entirely?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() { 
    int n; 
    cin >> n; 

    vector<vector<long long>> times(n, vector<long long>{0LL,0LL}); 
    long long a; 
    long long b; 
    for (int i = 0; i < n; i++) { 
        cin >> a >> b; 
        vector<long long> t = times[i];
        t[0] = b;
        t[1] = a;
    }

    sort(times.begin(), times.end());
    // Tuple is (end, start) !

    int movies_watched = 0;
    long long time_passed = 0LL; 

    for (int i = 0; i < n; i++) {
        // If the start time of this movie is geq the time that has passed so far, we can watch it 
        vector<long long> curr = times[i];
        long long start_time = curr[1];
        if (start_time >= time_passed) { 
            movies_watched += 1;
            time_passed = times[i][0];
        }
    }

    cout << movies_watched << "\n";
    return 0; 
}