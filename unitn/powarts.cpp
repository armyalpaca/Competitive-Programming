#include <bits/stdc++.h>
using namespace std;
#define MAXN 50005
vector<vector<array<int,2> > >graph(MAXN);
vector<int>dist(MAXN,2e9);
vector<vector<int> >adj(MAXN);
int up[MAXN][20];
void dijkstra(int P,int N,int M){
    vector<bool>vis(N,false);
    vector<array<int,2> >parent(N);
    parent[P]={P,0};
    dist[P]=0;
    priority_queue<array<int,2> >coda;
    coda.push({0,P});
    while(!coda.empty()){
        int nodo=coda.top()[1];
        coda.pop();
        if(vis[nodo])continue;
        vis[nodo]=true;
        for(auto x:graph[nodo]){
            if(vis[x[0]]||dist[x[0]]<=dist[nodo]+x[1])continue;
            parent[x[0]]={nodo,x[1]};
            dist[x[0]]=dist[nodo]+x[1];
            coda.push({-dist[x[0]],x[0]});
        }
    }
    for(int i=0;i<N;i++){
        if(i!=P){
            adj[parent[i][0]].push_back(i);
        }
    }
}
int tempo=0;
int Tin[MAXN],Tout[MAXN];
void dfs1(int nodo,int p){
    Tin[nodo]=tempo++;
    up[nodo][0]=p;
    for(int i=1;i<20;i++){
        up[nodo][i]=up[up[nodo][i-1]][i-1];
    }
    for(int x:adj[nodo]){
        dfs1(x,nodo);
    }
    Tout[nodo]=tempo++;
}
bool is_in(int a,int b){
    if(Tin[a]<=Tin[b]&&Tout[b]<=Tout[a])return true;
    return false;
}
int lca(int a,int b){
    if(is_in(a,b))return a;
    if(is_in(b,a))return b;
    for(int i=19;i>=0;i--){
        if(!is_in(up[a][i],b)){
            a=up[a][i];
        }
    }
    return up[a][0];
}

vector<int>lowest(MAXN);
vector<int>conta(MAXN,0);
void dfs2(int nodo){
    lowest[nodo]=nodo;
    for(auto x:graph[nodo]){
        if(dist[x[0]]+x[1]==dist[nodo]){
            if(Tin[lca(nodo,x[0])]<Tin[lowest[nodo]]){
                lowest[nodo]=lca(nodo,x[0]);
            }
        }
    }
    int suppris=0;
    for(int x:adj[nodo]){
        dfs2(x);
    }
    conta[nodo]++;
    conta[lowest[nodo]]+=conta[nodo];
    
}

vector<int>dijkstra2(int P,int N,int togli){
    vector<int>dist2(N,2e9);
    vector<bool>vis(N,false);
    dist2[P]=0;
    priority_queue<array<int,2> >coda;
    coda.push({0,P});
    while(!coda.empty()){
        int nodo=coda.top()[1];
        coda.pop();
        if(vis[nodo])continue;
        vis[nodo]=true;
        for(auto x:graph[nodo]){
            if(x[0]==togli)continue;
            if(vis[x[0]]||dist2[x[0]]<=dist2[nodo]+x[1])continue;
            dist2[x[0]]=dist2[nodo]+x[1];
            coda.push({-dist2[x[0]],x[0]});
        }
    }
    vector<int>lista;
    for(int i=0;i<N;i++){
        if(dist2[i]!=dist[i]){
            lista.push_back(i);
        }
    }
    return lista;
}

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N,M,P;
    cin>>N>>M>>P;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dijkstra(P,N,M);
    dfs1(P,P);
    dfs2(P);
    int nodo=-1;
    for(int i=0;i<N;i++){
        if(i!=P){
            if(nodo==-1||conta[nodo]<conta[i])nodo=i;
        }
    }
    vector<int>nodi=dijkstra2(P,N,nodo);
    cout<<conta[nodo]<<"\n";
    for(int x:nodi)cout<<x<<"\n";
}