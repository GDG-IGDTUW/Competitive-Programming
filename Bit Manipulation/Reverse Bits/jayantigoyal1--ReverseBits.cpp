#include <bits/stdc++.h>
using namespace std;

int main() {
    uint32_t n;
    cin>>n;
    uint32_t result=0;
    for(int i=0; i<32; i++){
        result<<=1;
        result |=(n&1);
        n>>=1;
    }
    cout<<result;
    return 0;
}
