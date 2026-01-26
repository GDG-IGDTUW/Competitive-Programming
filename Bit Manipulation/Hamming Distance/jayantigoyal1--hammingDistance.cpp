#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y;
    cin>>x>>y;
    int v=x^y;
    int cnt=0;
    while(v){
        cnt+=(v&1);
        v >>= 1;
    }
    cout<<cnt<<endl;
    return 0;
}
