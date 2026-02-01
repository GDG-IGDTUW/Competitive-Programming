#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    long long count=0;
    int l=0, r=n-1;
    while(l<r){
        if(a[l]+a[r]<=x){
            count += (r - l);
            l++;
        }
        else r--;
    }
    cout<<count<<endl;
    return 0;
}
