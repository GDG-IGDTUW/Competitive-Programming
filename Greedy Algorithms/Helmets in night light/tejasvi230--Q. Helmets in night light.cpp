#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<long long, long long>> people;
        for (int i = 0; i < n; i++) {
            people.push_back({b[i], a[i]});
        }

        // sort by sharing cost
        sort(people.begin(), people.end());

        long long ans = p;          // first person directly notified
        long long remaining = n - 1;

        for (auto &pr : people) {
            long long cost = pr.first;
            long long cap = pr.second;

            if (remaining == 0) break;
            if (cost >= p) break;   // direct is cheaper or equal

            long long use = min(cap, remaining);
            ans += use * cost;
            remaining -= use;
        }

        // remaining people via direct notification
        ans += remaining * p;

        cout << ans << "\n";
    }

    return 0;
}
