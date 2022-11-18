#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
vector<vector<int> >dist(MAXN,vector<int>(2,2e9));
vector<vector<array<int,2> > >adj(MAXN);
bool vis[MAXN][2];
int main(){
    int N,M;
    cin>>N>>M;
    priority_queue<array<int,2> >coda;
    array<int,2>nodi={0,N-1};
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});        
    }
    for(int i=0;i<2;i++){
        dist[nodi[i]][i]=0;
        coda.push({0,nodi[i]});
        while(!coda.empty()){
            int nodo=coda.top()[1];
            coda.pop();
            if(vis[nodo][i])continue;
            vis[nodo][i]=1;
            for(auto x:adj[nodo]){
                if(!vis[x[0]][i]&&dist[nodo][i]+x[1]<dist[x[0]][i]){
                    dist[x[0]][i]=dist[nodo][i]+x[1];
                    coda.push({-dist[x[0]][i],x[0]});
                }
            }
        }
    }
    long long ris=0;
    for(int i=0;i<N;i++){
        for(auto x:adj[i]){
            if(dist[i][0]+dist[x[0]][1]+x[1]==dist[N-1][0]){
                ris+=2*x[1];
            }
        }
    }
    cout<<ris<<"\n";
    
}