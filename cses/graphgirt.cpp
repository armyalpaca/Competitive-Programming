#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
vector<vector<int> >adj(MAXN);
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool>vis(N+1);
    vector<int>dist(N+1);
    vector<int>p(N+1);
    queue<int>coda;
    int ris=1e9;
    for(int i=1;i<=N;i++){
        fill(vis.begin(),vis.end(),false);
        dist[i]=0;
        vis[i]=1;
        p[i]=i;
        coda.push(i);
        while (!coda.empty()){
            int nodo=coda.front();
            coda.pop();
            for(int x:adj[nodo]){
                if(!vis[x]){
                    dist[x]=dist[nodo]+1;
                    vis[x]=1;
                    p[x]=nodo;
                    coda.push(x);
                }else if(p[nodo]!=x){
                    ris=min(ris,dist[x]+dist[nodo]+1);
                }
            }
        }
    }
    if(ris==1e9)ris=-1;
    cout<<ris<<"\n";
}