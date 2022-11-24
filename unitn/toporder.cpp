#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005 
vector<vector<int> >adj(MAXN);
vector<bool>vis(MAXN);
vector<int>topo;
void dfs(int nodo){
    vis[nodo]=1;
    for(int x:adj[nodo])if(!vis[x])dfs(x);
    topo.push_back(nodo);
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
    }
    for(int i=0;i<n;i++)if(!vis[i])dfs(i);
    reverse(topo.begin(),topo.end());
    for(int x:topo)cout<<x<<" ";
    cout<<"\n";
}