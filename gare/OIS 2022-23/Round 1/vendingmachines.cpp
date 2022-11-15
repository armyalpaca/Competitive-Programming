#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int>ar(n+1);
        for(int i=1;i<=n;i++)cin>>ar[i];
        bool ok=true;
        long long soldi=0;
        while(q--){
            int tmp;
            cin>>tmp;
            if(tmp>0)soldi+=tmp;
            else{
                soldi-=ar[-tmp];
                if(soldi<0)ok=false;
            }
        }
        if(ok)cout<<"OK\n";
        else cout<<"HACKER\n";
    }
}