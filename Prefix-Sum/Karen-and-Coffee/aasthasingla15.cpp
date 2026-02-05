#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    const int MAXT = 200000 + 5;

    // Step 1: Difference array to mark ranges
    vector<int> diff(MAXT, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    // Step 2: Prefix sum to get number of recipes recommending each temperature
    vector<int> freq(MAXT, 0);
    for (int i = 1; i < MAXT; i++) {
        freq[i] = freq[i - 1] + diff[i];
    }

    // Step 3: Prefix sum of admissible temperatures (freq >= k)
    vector<int> admissible(MAXT, 0);
    for (int i = 1; i < MAXT; i++) {
        admissible[i] = admissible[i - 1] + (freq[i] >= k);
    }

    // Step 4: Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << admissible[b] - admissible[a - 1] << "\n";
    }

    return 0;
}
