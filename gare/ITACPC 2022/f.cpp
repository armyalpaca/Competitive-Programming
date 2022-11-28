#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define mod 1000000007
typedef long long ll;
vector<ll>primi;
unordered_map<ll,ll>dp;
ll f(ll n){
    if(n==1)return 1;
    if(dp[n]!=0)return dp[n];
    ll ris=0;
    for(ll x:primi){
        if(n%x==0){
    
            ris+=f(n/x);
            ris%=mod;
        }
    }
    //cout<<n<<" "<<ris<<"\n";
    return dp[n]=ris;
}
int mat[2002][2002];
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<int> >adj(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<adj[i].size();j++){
            for(int p=j+1;p<adj[i].size();p++){
                mat[adj[i][j]][adj[i][p]]++;
                if(mat[adj[i][j]][adj[i][p]]>=K){
                    cout<<"YES\n";
                    return 0;
                }
                mat[adj[i][p]][adj[i][j]]++;
                if(mat[adj[i][p]][adj[i][j]]>=K){
                    cout<<"YES\n";
                    return 0;
                }
            }
        }

    }
    cout<<"NO\n";
    
}