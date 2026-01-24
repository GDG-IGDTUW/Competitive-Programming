#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long m,k,a1,ak;
        cin>>m>>k>>a1>>ak;
        long long temp=(m/k)*k;
        temp=min(temp, ak * k);
        temp=m-temp;
        m=max(0LL, temp-a1);
        long long ans=((m/k)+(m%k));
        if(a1>=(k-m%k)){
            long long ans2=1+(m/k);
            ans=min(ans,ans2);
        }
        cout<<ans<<endl;
    }
    return 0;
}