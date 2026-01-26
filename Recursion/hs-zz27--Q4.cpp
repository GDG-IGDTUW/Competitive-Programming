#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll helper(ll a,ll b){
    if(b==0) return 1;
    return a*helper(a,b-1);
}

int main(){
    ll a,b;cin>>a>>b;
    cout<<helper(a,b);
}
