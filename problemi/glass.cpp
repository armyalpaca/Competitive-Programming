#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
vector<vector<int> >adj(MAXN);
vector<int>C(MAXN);
int N,M;
vector<vector<int> >nodi(MAXN);
vector<int>prov(MAXN,-1);
vector<int>dist(MAXN);
vector<bool>vis(MAXN,false);
int bfs(int colore){
    queue<int>coda;
    for(int x:nodi[colore]){
        for(int y:adj[x]){
            if(C[y]!=colore){
                if(prov[x]!=-1&&prov[x]!=C[y])return 2;
                if(prov[x]==-1){
                    prov[x]=C[y];
                    vis[x]=1;
                    dist[x]=1;
                    coda.push(x);
                }
            }
        }
    }
    int ris=1e9;
    while(!coda.empty()){
        int nodo=coda.front();
        coda.pop();
        for(int x:adj[nodo]){
            if(C[x]!=colore)continue;
            if(!vis[x]){
                vis[x]=1;
                dist[x]=dist[nodo]+1;
                prov[x]=prov[nodo];
                coda.push(x);
            }else if(prov[x]!=prov[nodo]){
                ris=min(ris,dist[x]+dist[nodo]+1);
            }
        }
    }
    return ris;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>C[i];
        nodi[C[i]].push_back(i);
    }
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ris=2e9;
    for(int i=0;i<N;i++){
        ris=min(ris,bfs(i));
    }
    if(ris>1e8)ris=-1;
    cout<<ris<<"\n";

}