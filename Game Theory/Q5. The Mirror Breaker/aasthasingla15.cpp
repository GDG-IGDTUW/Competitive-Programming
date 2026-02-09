#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;
    int moves = 0;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();    // remove pair
            moves++;     // one move done
        } else {
            st.push(c);  // keep rune
        }
    }

    if (moves % 2 == 1) {
        cout << "Yes\n";  // Gemini wins
    } else {
        cout << "No\n";   // Twin wins
    }

    return 0;
}
