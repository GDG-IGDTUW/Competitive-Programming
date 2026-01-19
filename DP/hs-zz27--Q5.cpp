#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    // dp states:
    // prev2 -> maximum sum till index i-2
    // prev1 -> maximum sum till index i-1
    ll prev2=v[0];
    ll prev1=max(v[0],v[1]);

    // transition:
    // Either skip current element (prev1)
    // or take it and add to prev2
    for(int i=2;i<n;i++){
        ll cur=max(prev1,prev2+v[i]);
        prev2=prev1;
        prev1=cur;
    }
    cout<<prev1;
    return 0;
}
