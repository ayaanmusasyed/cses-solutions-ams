/**
 * There is a knight on an n \times n chessboard. 
 * For each square, print the minimum number of moves the knight needs to do to reach the top-left corner.
*/

#include <iostream> 
#include <vector> 
#include <deque>
#include <tuple>
#include <set>
using namespace std; 

int main() { 
    int n; 
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n,0));

    deque<tuple<int, int, int>> q = {make_tuple(0,0,0)};
    set<tuple<int,int>> visited; 

    while (!(q.empty())) { 
        tuple<int,int,int> info = q.front(); 
        q.pop_front(); 
        int x = get<0>(info); 
        int y = get<1>(info); 
        int moves = get<2>(info);
        tuple<int, int> coords = make_tuple(x,y); 
        visited.insert(coords);


    }

}