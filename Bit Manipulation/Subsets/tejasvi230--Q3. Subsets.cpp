#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int total = 1 << n;   // total subsets = 2^n

    // iterate over all bitmasks
    for (int mask = 0; mask < total; mask++) {
        cout << "[";

        bool first = true;
        for (int i = 0; i < n; i++) {
            // if i-th bit is set, include a[i]
            if (mask & (1 << i)) {
                if (!first) cout << ",";
                cout << a[i];
                first = false;
            }
        }

        cout << "]\n";
    }

    return 0;
}
