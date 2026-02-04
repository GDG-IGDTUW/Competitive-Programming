#include <iostream>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    int a[200002] = {0};

    while(n--) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }

    for(int i=1; i<=200000; i++)
        a[i] += a[i-1];

    for(int i=1; i<=200000; i++)
        a[i] = a[i]>=k ? 1 : 0;

    for(int i=1; i<=200000; i++)
        a[i] += a[i-1];

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r]-a[l-1] << endl;
    }
}
