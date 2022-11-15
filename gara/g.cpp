#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int N,M;
bool mat[100][1000];
int dp2[1<<15][102];
long long dp[1<<15][102];
int f2(int a,int b){
    if(b==M)return 0;
    if(dp2[a][b]!=-1)return dp2[a][b];
    dp2[a][b]=0;
    for(int i=0;i<N;i++){
        if(!(a&(1<<i))&&mat[i][b]){
            dp2[a][b]=max(dp2[a][b],1+f2(a|(1<<i),b+1));
        }
    }
    dp2[a][b]=max(dp2[a][b],f2(a,b+1));
    return dp2[a][b];
}
int massimo=0;
ll f(int a,int b){
    if(b==M){
        int conta=0;
        for(int i=0;i<N;i++){
            if(a&(1<<i))conta++;
        }
        return (conta==massimo);
    }
    if(b==M)return 0;
    if(dp[a][b]!=-1)return dp[a][b];

    dp[a][b]=0;
    for(int i=0;i<N;i++){
        if(!(a&(1<<i))&&mat[i][b]){
            dp[a][b]+=f(a|(1<<i),b+1);
            dp[a][b]%=mod;
        }
    }
    dp[a][b]+=f(a,b+1);
    dp[a][b]%=mod;
    return dp[a][b];
}

int main(){
    
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)cin>>mat[i][j];
    }
    for(int i=0;i<(1<<15);i++){
        for(int j=0;j<101;j++)dp[i][j]=dp2[i][j]=-1;
    }
    massimo=f2(0,0);
    cout<<f(0,0)<<"\n";
}