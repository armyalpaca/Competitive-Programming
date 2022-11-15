#include <bits/stdc++.h>
using namespace std;
#define MAXH 2500
int main(){
    int N;
    cin>>N;
    vector<int>H(N);
    for(int i=0;i<N;i++){
        cin>>H[i];
        H[i]+=100;
    }
    vector<long long>dp1(MAXH,1e15),dp2(MAXH,1e15);
    vector<long long>prefix(MAXH,0),suffix(MAXH,0);
    for(int i=N-1;i>=0;i--){
        
        for(int j=0;j<MAXH;j++){
            if(j!=MAXH-1&&j!=0)dp1[j]=(j-H[i])*(j-H[i])+suffix[j+1];
            if(j!=0&&j!=MAXH-1)dp2[j]=(j-H[i])*(j-H[i])+prefix[j-1];
        }
        prefix[0]=dp1[0];
        for(int j=1;j<MAXH;j++)prefix[j]=min(prefix[j-1],dp1[j]);
        suffix[MAXH-1]=dp2[MAXH-1];
        for(int j=MAXH-2;j>=0;j--)suffix[j]=min(suffix[j+1],dp2[j]);
    }
    long long ris=1e18;
    for(int i=0;i<MAXH;i++){
        ris=min(ris,dp1[i]);
        ris=min(ris,dp2[i]);
    }
    cout<<ris<<"\n";
}