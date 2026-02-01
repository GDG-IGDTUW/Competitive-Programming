#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long n;
        int m, q;
        cin>>n>>m>>q;
        vector<long long> b(m);
        for(int i=0; i<m; i++){
            cin>>b[i];
        }
        sort(b.begin(), b.end());
        while(q--){
            long long a;
            cin>>a;
            auto it = lower_bound(b.begin(), b.end(), a);

            //to the left of all teachers
            if (it==b.begin()) cout<<(b[0]-1)<<endl;

            //to the right of all teachers
            else if (it==b.end()) cout<<(n-b[m-1])<<endl;
            
            //between two teachers
            else {
                long long R = *it;
                long long L = *(it-1);
                cout<<(R-L)/2<<endl;
            }
        }
    }

    return 0;
}
