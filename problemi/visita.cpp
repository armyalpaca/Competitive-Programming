#include <bits/stdc++.h>
using namespace std;
#define MAXN 20000
vector<bool>vis(MAXN);
int dfs(int nodo,vector<vector<int> >&adj){
    vis[nodo]=1;
    int ris=0;
    for(int x:adj[nodo])if(!vis[x])ris+=dfs(x,adj);
    return ris+1;
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N,M,S;
    cin>>N>>M>>S;
    vector<vector<int> >adj(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cout<<dfs(S,adj)<<"\n";
}