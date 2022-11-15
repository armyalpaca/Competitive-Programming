#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,K;
#define MAXN 1005
vector<int>ar(MAXN);
ll dp[MAXN][MAXN][4];
ll f(int i,int turni,int stesso){
    i%=N;
    if(turni==0)return 0;
    if(dp[i][turni][stesso]!=-1e18)return dp[i][turni][stesso];
    if(stesso==3)return dp[i][turni][stesso]=f(i,turni-1,0);
    //cout<<i<<" "<<turni<<" "<<stesso<<"\n";
    for(int j=2;j<=12;j++){
        if(j!=2&&j!=12)dp[i][turni][stesso]=max(dp[i][turni][stesso],f(i+j,turni-1,0)+ar[(i+j)%N]);
        if(j%2==0)dp[i][turni][stesso]=max(dp[i][turni][stesso],f(i+j,turni,stesso+1)+ar[(i+j)%N]);
    }
    return dp[i][turni][stesso];
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++)cin>>ar[i];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=K;j++){
            for(int pp=0;pp<4;pp++)dp[i][j][pp]=-1e18;
        }
    }
    cout<<f(0,K,0)<<"\n";
    
}