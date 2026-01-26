#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(n, 1000000000); // start large
        vector<bool> fixed(n, false);

        vector<array<int,3>> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
            queries[i][1]--, queries[i][2]--;
        }

        // Handle c = 1 (force min = k)
        for (auto &qr : queries) {
            if (qr[0] == 1) {
                int l = qr[1], r = qr[2];
                bool placed = false;
                for (int i = l; i <= r; i++) {
                    if (!fixed[i]) {
                        a[i] = k;
                        fixed[i] = true;
                        placed = true;
                        break;
                    }
                }
                // if not placed, one k already exists in range
            }
        }

        // Handle c = 2 (force MEX = k)
        for (auto &qr : queries) {
            if (qr[0] == 2) {
                int l = qr[1], r = qr[2];

                // k must not appear
                for (int i = l; i <= r; i++) {
                    if (a[i] == k) {
                        a[i] = k + 1;
                        fixed[i] = true;
                    }
                }

                // ensure 0..k-1 appear
                int need = 0;
                for (int i = l; i <= r && need < k; i++) {
                    if (!fixed[i]) {
                        a[i] = need;
                        fixed[i] = true;
                        need++;
                    }
                }
            }
        }

        // Fill remaining positions
        for (int i = 0; i < n; i++) {
            if (!fixed[i]) {
                a[i] = k + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
