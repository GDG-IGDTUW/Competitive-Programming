# 1. Little Girl and Maximum Sum

### Description
You are given an array `a` of `n` integers and `q` queries.

Each query is described by two integers `l` and `r`  
(1 ≤ l ≤ r ≤ n), meaning that every element `a[l]` to `a[r]`
will be counted once.

For each index `i`, let `cnt[i]` be the number of queries that include index `i`.

You are allowed to **reorder the array `a`** in any way before processing the queries.

Your task is to maximize the total sum:

\[
\sum_{i=1}^{n} a[i] \times cnt[i]
\]

---

### Input
- The first line contains two integers `n` and `q`  
  (1 ≤ n, q ≤ 2 × 10⁵)
- The second line contains `n` integers `a[i]`
- The next `q` lines each contain two integers `l` and `r`

---

### Output
Print the maximum possible sum.

---

### Sample
**Input:**
3 3
5 3 2
1 2
2 3
1 3

**Output:**
25
