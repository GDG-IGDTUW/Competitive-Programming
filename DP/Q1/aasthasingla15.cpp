#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    long long prev2 = 0; // F(0)
    long long prev1 = 1; // F(1)
    long long current;

    for (int i = 2; i <= N; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    cout << prev1;

    return 0;
}
