#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<vector<int> >adj(MAXN);
vector<bool>vis(MAXN);
int low[MAXN];
int tempo=0;
int T[MAXN];
vector<int>ris;
void dfs(int nodo,int p){
    vis[nodo]=1;
    T[nodo]=tempo++;
    low[nodo]=T[nodo];
    bool ok=true;
    int conta=0;
    for(int x:adj[nodo]){
        if(x==p)continue;
        if(vis[x])low[nodo]=min(low[nodo],T[x]);
        else{
            conta++;
            dfs(x,nodo);
            if(low[x]>=T[nodo])ok=false;
            low[nodo]=min(low[nodo],low[x]);
        }
    }
    if(nodo==1&&conta>1)ris.push_back(nodo);
    else if(nodo!=1&&!ok)ris.push_back(nodo);
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
    dfs(1,1);
    cout<<ris.size()<<"\n";
    for(auto x:ris)cout<<x<<" ";
    cout<<"\n";

}