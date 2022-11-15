#include <bits/stdc++.h>
using namespace std;
#define MAXN 50005


int N,M,Q;
vector<vector<int> >adj1(MAXN);
vector<vector<int> >inv_adj(MAXN);
vector<vector<int> >adj2(MAXN);
int CC[MAXN];
vector<bool>vis(MAXN);
vector<int>topo;
void dfs1(int nodo){//topo 1
    vis[nodo]=1;
    for(int x:adj1[nodo])if(!vis[x])dfs1(x);
    topo.push_back(nodo);
}
void dfs2(int nodo,int c){// grafo inverso
    vis[nodo]=1;
    CC[nodo]=c;
    for(int x:inv_adj[nodo])if(!vis[x])dfs2(x,c);
}

vector<bitset<50000> >reach;
void comprimi(){
    for(int i=1;i<=N;i++)if(!vis[i])dfs1(i);
    reverse(topo.begin(),topo.end());
    fill(vis.begin(),vis.end(),false);
    int c=0;
    for(int x:topo){
        if(!vis[x])dfs2(x,c++);
    }
    for(int i=1;i<=N;i++){
        for(int x:adj1[i]){
            if(CC[i]!=CC[x])adj2[CC[i]].push_back(CC[x]);
        }
    }
    reach.resize(c);
    for(int i=c-1;i>=0;i--){
        reach[i].set(i);
        for(int x:adj2[i]){
            reach[i]|=reach[x];
        }
    }
}



int main(){
    cin>>N>>M>>Q;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj1[a].push_back(b);
        inv_adj[b].push_back(a);
    }
    comprimi();
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(CC[a]==CC[b]||reach[CC[a]].test(CC[b])){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}