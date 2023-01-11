#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    int n,m;
    cin>>n>>m;
    vector<array<int,3> >archi(m);
    for(int i=0;i<m;i++){
        cin>>archi[i][1]>>archi[i][2]>>archi[i][0];
    }
    sort(archi.rbegin(),archi.rend());
    vector<map<int,long long> >mappa(n+1);
    for(auto x:archi){
        mappa[x[1]][x[0]]+=(1+mappa[x[2]][x[0]+1]);
        mappa[x[1]][x[0]]%=mod;
        mappa[x[2]][x[0]]+=(1+mappa[x[1]][x[0]+1]);
        mappa[x[2]][x[0]]%=mod;
    }
    long long somma=0;
    for(int i=1;i<=n;i++){
        for(auto x:mappa[i]){
            somma+=x.second;
            somma%=mod;
        }
    }
    somma=(somma-m+mod)%mod;
    cout<<somma<<"\n";

}