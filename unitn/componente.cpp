#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
vector<vector<int> >adj(MAXN),inv_adj(MAXN);
vector<int>topo;
vector<bool>vis(MAXN);
void dfs1(int nodo){
    vis[nodo]=1;
    for(int x:adj[nodo])if(!vis[x])dfs1(x);
    topo.push_back(nodo);
}
int dfs2(int nodo){
    vis[nodo]=1;
    int ris=1;
    for(int x:inv_adj[nodo]){
        if(!vis[x])ris+=dfs2(x);
    }
    return ris;
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        inv_adj[b].push_back(a);
    }
    for(int i=0;i<n;i++)if(!vis[i])dfs1(i);
    for(int i=0;i<n;i++)vis[i]=0;
    int ris=0;
    reverse(topo.begin(),topo.end());
    for(int x:topo){
        if(!vis[x])ris=max(ris,dfs2(x));
    }
    cout<<ris<<"\n";
}