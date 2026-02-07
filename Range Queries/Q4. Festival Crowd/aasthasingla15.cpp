#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        int block_size = 450; // sqrt(2*10^5)
        int this_block = l / block_size;
        int other_block = other.l / block_size;
        if (this_block != other_block)
            return this_block < other_block;
        return (this_block & 1) ? (r < other.r) : (r > other.r); // zig-zag to reduce time
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Coordinate compression
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--; // 0-based indexing
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    vector<int> ans(q);
    vector<int> freq(b.size(), 0);
    int cur_l = 0, cur_r = -1, distinct = 0;

    auto add = [&](int idx) {
        if (++freq[a[idx]] == 1) distinct++;
    };
    auto remove = [&](int idx) {
        if (--freq[a[idx]] == 0) distinct--;
    };

    for (auto &query : queries) {
        while (cur_l > query.l) add(--cur_l);
        while (cur_r < query.r) add(++cur_r);
        while (cur_l < query.l) remove(cur_l++);
        while (cur_r > query.r) remove(cur_r--);
        ans[query.idx] = distinct;
    }

    for (int x : ans) cout << x << "\n";

    return 0;
}
