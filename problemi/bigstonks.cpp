#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    vector<vector<array<int,2> > >ar(N,vector<array<int,2> >(K));
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cin>>ar[i][j][0]>>ar[i][j][1];
        }
    }
    vector<double>best(K);
    //best[i]=best[i+1]/price[i]
    for(int i=0;i<K;i++)best[i]=ar[N-1][i][1];
    double ris=1;
    for(int i=N-2;i>=0;i--){
        double supp=1;
        for(int j=0;j<K;j++)supp=max(supp,best[j]);
        for(int j=0;j<K;j++){
            ris=max(ris,best[j]/ar[i][j][0]);
            best[j]=max(supp,best[j]);
        }
    }
    cout<<fixed<<setprecision(10)<<ris<<"\n";
}