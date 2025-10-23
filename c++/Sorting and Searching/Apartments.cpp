/**
 * There are n applicants and m free apartments. 
 * Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
 * Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
*/

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int main() { 
    int n; 
    int m; 
    unsigned long long k; 
    cin >> n >> m >> k; 
    
    int ppl = 0; 
    int apt = 0; 

    int res = 0; 

    vector<unsigned long long> people; 
    unsigned long long x = 0ULL; 
    for (int i = 0; i < n; i++) { 
        cin >> x;
        people.push_back(x); 
    }
    sort(people.begin(), people.end());

    vector<unsigned long long> apartments; 
    unsigned long long y = 0ULL; 
    for (int j = 0; j < m; j++) { 
        cin >> y; 
        apartments.push_back(y); 
    }
    sort(apartments.begin(), apartments.end());

    while (ppl < n && apt < m) { 
        // Apartment is too small for this candidate 
        if (apartments[apt] + k < people[ppl]) { 
            apt += 1;
        } 
        // Apartment is too big -> move on to next person 
        else if (apartments[apt] > people[ppl] + k) { 
            ppl += 1;
        } 
        else{ 
            ppl += 1; 
            apt += 1;
            res += 1;
        }
    }

    cout << res << "\n";
    return 0;
}