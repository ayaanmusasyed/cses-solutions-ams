/**
 * You are given a playlist of a radio station since its establishment. 
 * The playlist has a total of n songs.
 * 
 * What is the longest sequence of successive songs where each song is unique?
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <deque> 
using namespace std; 

int main() { 

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    unordered_set<long> songs = {}; 
    songs.reserve(n * 2);
    songs.max_load_factor(0.7f);
    deque<long> playlist;
    int res = 0; 
    int size = 0;
    for (int i = 0; i < n; i++) { 
        long x; 
        cin >> x; 
        
        // Check if current song is in playlist
        auto it = songs.find(x);
        if (it != songs.end()) { 
            while (playlist.front() != x) { 
                long y = playlist.front();
                playlist.pop_front();
                songs.erase(y);
            }
            playlist.pop_front();
            playlist.push_back(x);
            songs.insert(x);
        } 

        // Not in playlist -> add to deque 
        else { 
            playlist.push_back(x);
            songs.insert(x); 
        }

        size = playlist.size();
        res = max(res,size);
    }

    cout << res << "\n";
    return 0;
}