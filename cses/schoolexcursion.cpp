#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<vector<int> >adj(MAXN);
vector<bool>vis(MAXN);
int dfs(int nodo){
    int ris=1;
    vis[nodo]=1;
    for(int x:adj[nodo])if(!vis[x])ris+=dfs(x);
    return ris;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k=sqrt(n);
    
    vector<int>piccoli(k,0);
    unordered_map<int,int>grandi;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int tmp=dfs(i);
            if(tmp<k)piccoli[tmp]++;
            else grandi[tmp]++;
        }
    }
    vector<pair<int,int> >ok;
    for(int i=1;i<k;i++){
        if(piccoli[i]>0)
        ok.push_back({i,piccoli[i]});
    }
    for(auto x:grandi){
        ok.push_back(x);
    }
    vector<vector<int> >dp(2,vector<int>(n+1,-1));
    dp[1][0]=0;
    for(int i=0;i<ok.size();i++){
        for(int j=0;j<=n;j++){
            if(dp[(i+1)&1][j]>=0)dp[i&1][j]=0;
            else if(j-ok[i].first>=0&&dp[i&1][j-ok[i].first]>=0&&dp[i&1][j-ok[i].first]<ok[i].second){
                dp[i&1][j]=dp[i&1][j-ok[i].first]+1;
            }else{
                dp[i&1][j]=-1;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<(dp[(ok.size()+1)%2][i]>=0?1:0);
    cout<<"\n";
}