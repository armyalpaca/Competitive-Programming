#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005 
vector<vector<int> >adj(MAXN);
vector<bool>vis(MAXN);
vector<int>topo;
vector<int>ris(MAXN);
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
    int r=0;
    reverse(topo.begin(),topo.end());
    for(int i=n-1;i>=0;i--){
        for(int x:adj[topo[i]]){
            ris[topo[i]]=max(ris[topo[i]],ris[x]);
        }
        ris[topo[i]]++;
        r=max(r,ris[topo[i]]);
    }
    cout<<r-1<<"\n";
}