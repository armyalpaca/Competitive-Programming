#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<bool>vis(MAXN);
vector<vector<int> >graph(MAXN);
vector<int>toposort;
void dfs1(int nodo,vector<vector<int> >&adj){
    vis[nodo]=1;
    for(int x:adj[nodo])if(!vis[x])dfs1(x,adj);
    toposort.push_back(nodo);
}
vector<int>comp(MAXN);
void dfs2(int nodo,int cc,vector<vector<int> >&adj){
    vis[nodo]=1;
    comp[nodo]=cc;
    for(int x:adj[nodo]){
        if(!vis[x]){
            dfs2(x,cc,adj);
        }else if(comp[x]!=cc){
            graph[comp[x]].push_back(cc);
        }
    }
}
vector<long long>conta(MAXN,-1);
long long dfs3(int nodo,int D){
    if(conta[nodo]!=-1)return conta[nodo];
    if(nodo==comp[D])return conta[nodo]=1;
    conta[nodo]=0;
    for(int x:graph[nodo]){
        conta[nodo]+=dfs3(x,D);
    } 
    return conta[nodo];
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N,M,S,D;
    cin>>N>>M>>S>>D;
    vector<vector<int> >adj(N),inv_adj(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        inv_adj[b].push_back(a);
    }
    for(int i=0;i<N;i++)if(!vis[i])dfs1(i,adj);
    for(int i=0;i<N;i++)vis[i]=false;
    int cc=0;
    reverse(toposort.begin(),toposort.end());
    for(int x:toposort){
        if(!vis[x])dfs2(x,cc++,inv_adj);
    }
    cout<<dfs3(comp[S],D)<<"\n";

}