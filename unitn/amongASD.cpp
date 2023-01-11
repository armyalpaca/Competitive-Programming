#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
int N,M,K,I,S,F;
vector<vector<int> >adj(MAXN),inv_adj(MAXN);
vector<array<int,5> >archi(MAXN+1000),confarchi;
vector<bool>vis(MAXN);
vector<int>topo_sort;
void dfs1(int nodo){
    vis[nodo]=1;
    for(int i:adj[nodo]){
        if(!vis[archi[i][1]]){
            dfs1(archi[i][1]);
        }
    }
    topo_sort.push_back(nodo);
}
vector<int>CC(MAXN);
vector<vector<int> >comp(MAXN);
int c=0;
void dfs2(int nodo,int cc){
    CC[nodo]=cc;
    comp[cc].push_back(nodo);
    vis[nodo]=1;
    for(int x:inv_adj[nodo]){
        if(!vis[x]){
            dfs2(x,cc);
        }
    }
}

//SPFA with Tarjan Trick 

void dijkstra(int start,vector<int>&dist,vector<int>&p){
    fill(dist.begin(),dist.end(),1e9);
    fill(p.begin(),p.end(),-1);
    fill(vis.begin(),vis.end(),false);
    queue<int>coda;
    dist[start]=0;
    p[start]=-1;
    for(int cc=0;cc<c;cc++){
        for(int nodo:comp[cc]){
            if(dist[nodo]!=1e9){
                coda.push(nodo);
                vis[nodo]=1;
            }
        }
        while(!coda.empty()){
            int nodo=coda.front();
            coda.pop();
            vis[nodo]=0;
            for(int i:adj[nodo]){
                auto arco=archi[i];
                if(dist[arco[1]]>dist[nodo]+arco[2]){
                    dist[arco[1]]=dist[nodo]+arco[2];
                    p[arco[1]]=i;
                    if(!vis[arco[1]]&&CC[arco[1]]==cc){
                        coda.push(arco[1]);
                        vis[arco[1]]=1;
                    }
                }
            }
        }

    }
    
}

int main(){
    clock_t tStart=clock();
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin.tie(0);ios_base::sync_with_stdio(false);
    cin>>N>>M>>K>>I>>S>>F;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        archi[i]={b,a,c,c,0};
        adj[b].push_back(i);
        inv_adj[a].push_back(b);
    }
    for(int i=0;i<K;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        archi[i+M]={b,a,c,d,1};
        adj[b].push_back(i+M);
        inv_adj[a].push_back(b);
    }

    //Trovo SCC per rendere SPFA più veloce
    for(int i=0;i<N;i++)if(!vis[i])dfs1(i);
    reverse(topo_sort.begin(),topo_sort.end());
    fill(vis.begin(),vis.end(),false);
    for(int x:topo_sort)if(!vis[x])dfs2(x,c++);

    int meglio=2;
    confarchi=archi;
    vector<int>dist(N),parent(N);
    dijkstra(F,dist,parent);
    if(dist[I]<dist[S]){
        meglio=1;
    }else if(dist[I]==dist[S]){
        meglio=0;
    }
    while(meglio!=1){
        dijkstra(F,dist,parent);
        int tmp=S;
        bool ok=false;
        int i=-1;
        while(parent[tmp]!=-1){ //trovo gli archi modificabili che sono nel shortest path tra S e F
            if(archi[parent[tmp]][2]!=archi[parent[tmp]][3]){
                i=parent[tmp];
                break;
            }
            tmp=archi[parent[tmp]][0];
        }
        if(i==-1)break;
        archi[i][2]=archi[i][3];
        dijkstra(F,dist,parent);
        if(dist[I]<dist[S]){
            meglio=1;
            confarchi=archi;

        }else if(dist[I]==dist[S]&&meglio==2){
            meglio=0;
            confarchi=archi; 
        }
    }
    archi=confarchi;
    dijkstra(F,dist,parent);
    cout<<meglio<<"\n";
    cout<<dist[I]<<" "<<dist[S]<<"\n";
    for(int i=M;i<M+K;i++){
        cout<<archi[i][2]<<" ";
    }
    cout<<"\n";
    vector<int>stanze;
    int tmp=I;
    while(tmp!=-1){
        stanze.push_back(tmp);
        if(parent[tmp]==-1)break;
        tmp=archi[parent[tmp]][0];
    }
    cout<<stanze.size()<<"\n";
    for(int x:stanze)cout<<x<<" ";
    cout<<"\n";
    cerr<<clock()-tStart<<"\n";
}