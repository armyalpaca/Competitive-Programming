#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<vector<int> >adj(MAXN);
vector<bool>vis(MAXN);
int low[MAXN];
int tempo=0;
int T[MAXN];
vector<pair<int,int> >ris;
void dfs(int nodo,int p){
    vis[nodo]=1;
    T[nodo]=tempo++;
    low[nodo]=T[nodo];
    for(int x:adj[nodo]){
        if(x==p)continue;
        if(vis[x])low[nodo]=min(low[nodo],T[x]);
        else{
            dfs(x,nodo);
            if(low[x]>T[nodo])ris.push_back({x,nodo});
            low[nodo]=min(low[nodo],low[x]);
        }
    }
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
    for(auto x:ris)cout<<x.first<<" "<<x.second<<"\n";

}