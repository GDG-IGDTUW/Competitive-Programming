#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> pref(N + 1, vector<int>(M + 1, 0));

    // build prefix sum of zero-cells
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int x;
            cin >> x;
            int isZero = (x == 0);
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1]
                       - pref[i - 1][j - 1] + isZero;
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        // count zeros in the rectangle
        int zeros = pref[C][D]
                  - pref[A - 1][D]
                  - pref[C][B - 1]
                  + pref[A - 1][B - 1];

        if (zeros > 0) cout << 0 << "\n";
        else cout << 1 << "\n";
    }

    return 0;
}
