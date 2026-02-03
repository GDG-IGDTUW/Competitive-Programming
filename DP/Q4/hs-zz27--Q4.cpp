#include <bits/stdc++.h>
using namespace std;
#define ll long long
// using kdane's algorithm 
int main() {
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    ll mx=v[0]; // stores max subarray sum so far
    ll curr=v[0];

    for(int i=1;i<n;i++){
        // either start a new subarray or continue the previous one
        curr=max(v[i],curr+v[i]);
        mx=max(mx,curr);
    }
    cout<<mx<<"\n";
    return 0;
}
