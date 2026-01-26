#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll hell=1e9+7;

ll fastpow(ll a,ll e){
    if(a==0 && e==0) return 1;
    ll res=1;
    a%=hell;
    while(e){
        if(e&1) res=(res*a)%hell;
        a=(a*a)%hell;
        e>>=1;
    }
    return res;
}

int main(){
    int t; cin>>t;
    while(t--){
        ll a,e;
        cin>>a>>e;
        cout<<fastpow(a,e)<<' ';
    }
}
