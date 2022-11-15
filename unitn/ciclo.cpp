#include <bits/sdtc++.h>
using namespace std;
vector<int>low,disc;
int tempo=0;
vector<bool>vis;
vector<vector<int> >adj;
stack<int>st;
vector<bool>in_stack;
void dfs(int nodo){
    low[nodo]=disc[nodo]=tempo++;
    in_stack[nodo]=1;
    for(int x:adj[nodo]){
        if(!vis[x]){
            dfs(x);
        }
        if(in_stack[x])low[nodo]=min(low[nodo],low[x]);
    }
    in_stack[nodo]=0;
}
void dfs2(int nodo,int cc){
    C[nodo]=cc;
    for(int x:adj[nodo])if(low[x]==cc&&!vis[x])dfs2(x,cc);
}
int main(){
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i);
    }

    for(int i=0;i<n;i++){
        if(!vis[i])dfs2(i,low[i]);
    }
}