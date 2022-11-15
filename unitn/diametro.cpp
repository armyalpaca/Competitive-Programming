#include <bits/stdc++.h>
using namespace std;
int bfs(int S,int N,vector<vector<int> >&adj,vector<int>&dist){
    vector<bool>vis(N,false);
    
    int massimo=S;
    queue<int>coda;
    coda.push(S);
    vis[S]=1;
    dist[S]=0;
    while(!coda.empty()){
        int nodo=coda.front();
        if(dist[nodo]>dist[massimo])massimo=nodo;
        coda.pop();
        for(int x:adj[nodo]){
            if(!vis[x]){
                dist[x]=dist[nodo]+1;
                vis[x]=1;
                coda.push(x);
            }
        }
    }
    return massimo;
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N,M;
    cin>>N>>M;
    vector<vector<int> >adj(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>dist(N);
    int ris=0;
    for(int i=0;i<N;i++){
        int tmp=bfs(i,N,adj,dist);
        ris=max(ris,dist[tmp]);
    }
    cout<<ris<<"\n";

}