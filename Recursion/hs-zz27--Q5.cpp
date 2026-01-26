#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll helper(vector<ll>& a,int i){
    if(i==a.size()-1) return a[i];
    return max(a[i],helper(a,i+1));
}

int main(){
    int n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<helper(a,0);
}
