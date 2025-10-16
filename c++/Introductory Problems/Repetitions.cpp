/**
 * You are given a DNA sequence: a string consisting of characters A, C, G, and T. 
 * Your task is to find the longest repetition in the sequence. 
 * This is a maximum-length substring containing only one type of character.
*/

#include <iostream>
#include <string>
using namespace std; 

int main() { 
    string s; 
    cin >> s; 

    unsigned long long res = 0ULL; 
    unsigned long long y = 0ULL; 
    unsigned int n = s.size(); 

    unsigned int i = 0U; 
    
    char prev; 
    char curr; 
    while (i < n) { 
        if (i == 0) { 
            y += 1; 
            i += 1; 
        } else { 
            prev = s[i - 1];
            curr = s[i];
            if (prev == curr) { 
                y += 1;
            } else { 
                y = 1;
            }

            i += 1;
        }

        if (y > res) { 
            res = y;
        }
    }
    cout << res << "\n";
    return 0;
}

