/**
 * There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
 * Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<long long> tickets;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        tickets.insert(x);
    }

    while (m--) {
        long long mx; cin >> mx;
        auto it = tickets.upper_bound(mx);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}
