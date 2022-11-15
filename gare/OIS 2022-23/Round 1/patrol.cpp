#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
vector<vector<int> >adj(MAXN);
int mod=420;
bool vis[MAXN][420];
int dist[MAXN][420];
bool ok[MAXN][420];
int main(){
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<K;i++){
        int l;
        cin>>l;
        for(int j=0;j<l;j++){
            int tmp;
            cin>>tmp;
            for(int pp=j;pp<420;pp+=l){
                ok[tmp][pp]=1;
            }
        }
    }
    dist[0][0]=0;
    vis[0][0]=1;
    queue<array<int,2> >coda;
    coda.push({0,0});
    int ris=2e9;
    while(!coda.empty()){
        int nodo=coda.front()[0];
        int tempo=coda.front()[1];
        if(nodo==N-1){
            ris=min(ris,dist[nodo][tempo]);
        }
        coda.pop();
        for(int x:adj[nodo]){
            if(ok[x][(tempo+1)%mod]||vis[x][(tempo+1)%mod])continue;
            vis[x][(tempo+1)%mod]=1;
            dist[x][(tempo+1)%mod]=dist[nodo][tempo]+1;
            coda.push({x,(tempo+1)%mod});
        }
        if(!vis[nodo][(tempo+1)%mod]&&!ok[nodo][(tempo+1)%mod]){
            dist[nodo][(tempo+1)%mod]=dist[nodo][tempo]+1;
            coda.push({nodo,(tempo+1)%mod});
        }
    }
    if(ris==2e9)ris=-1;
    cout<<ris<<"\n";


}