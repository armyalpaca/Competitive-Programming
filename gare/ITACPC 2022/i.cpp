#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef long long ll;
vector<int>ar(MAXN);
vector<vector<int> >adj(MAXN),inv_adj(MAXN),adj2(MAXN);
vector<bool>vis(MAXN);
vector<ll>S(MAXN);
vector<int>topo;
vector<int>C(MAXN);
void dfs1(int nodo){
    vis[nodo]=1;
    for(int x:adj[nodo]){
        if(!vis[x])dfs1(x);
    }
    topo.push_back(nodo);
}
void dfs2(int nodo,int cc){
    vis[nodo]=1;
    C[nodo]=cc;
    S[cc]+=ar[nodo];
    for(int x:inv_adj[nodo]){
        if(!vis[x])dfs2(x,cc);
        else if(C[x]!=C[nodo]){
            adj2[C[x]].push_back(C[nodo]);
        }
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<N;i++)cin>>ar[i];
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        inv_adj[b].push_back(a);
    }
    for(int i=0;i<N;i++){
        if(!vis[i])dfs1(i);
    }
    for(int i=0;i<N;i++)vis[i]=0;
    reverse(topo.begin(),topo.end());
    int cc=0;
    for(int x:topo){
        if(!vis[x]){
            dfs2(x,cc++);
        }
    }
    vector<ll>ris(MAXN);
    vector<bool>ok(MAXN);
    ok[C[N-1]]=1;
    for(int i=cc-1;i>=0;i--){
        ris[i]=0;
        for(int x:adj2[i]){
            if(ok[x]){
                ris[i]=max(ris[i],ris[x]);
                ok[i]=1;
            }
        }
        if(ok[i])ris[i]+=S[i];
    }
    cout<<ris[C[0]]<<"\n";
}
