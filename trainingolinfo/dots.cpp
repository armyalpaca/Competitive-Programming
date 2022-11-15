#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define MAXM 100005
vector<vector<int> >adj(MAXN);
vector<array<int,2> >archi;
vector<int>topo;
vector<bool>vis(MAXN);
void dfs(int nodo){
    vis[nodo]=1;
    for(int x:adj[nodo]){
        if(!vis[x])dfs(x);
    }
    topo.push_back(nodo);
}
vector<int>pos(MAXN);
vector<vector<int> >adj2(MAXN);
vector<pair<int,int> >riss;
void dfs2(int nodo,int p,bool a){
    vis[nodo]=1;
    for(int x:adj2[nodo]){
        if(a){
            riss.push_back({x,nodo});
            if(!vis[x])dfs2(x,nodo,true);
            a=false;
        }else{
            riss.push_back({nodo,x});
            if(!vis[x])dfs2(x,nodo,false);
        }
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        archi.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<N;i++)if(!vis[i])dfs(i);
    reverse(topo.begin(),topo.end());
    for(int i=0;i<N;i++)pos[topo[i]]=i;
    for(auto x:archi){
        if(pos[x[0]]<pos[x[1]]){
            adj2[x[0]].push_back(x[1]);
        }else{
            adj2[x[1]].push_back(x[0]);
        }
    }
    for(int i=0;i<N;i++)vis[i]=false;
    for(int x:topo){
        if(!vis[x])dfs2(x,-1,1);
    }
    for(auto x:riss)cout<<x.first<<" "<<x.second<<"\n";
}   