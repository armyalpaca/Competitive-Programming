#include <bits/stdc++.h>
using namespace std;
#define MAXN 50005
vector<vector<int> >adj(MAXN),adj2(MAXN);
vector<bool>vis(MAXN);
int cc[MAXN],dist[MAXN],Tin[MAXN],Tout[MAXN],st[MAXN][20];
int tempo=0;
int lib=0;
void dfs1(int nodo,int p){
    st[nodo][0]=p;
    vis[nodo]=1;
    cc[nodo]=-1;
    vector<int>supp;
    for(int x:adj[nodo]){
        if(x!=p&&vis[x]){
            supp.push_back(x);
            if(dist[x]+1<dist[nodo]){
                dist[nodo]=dist[x]+1;
                st[nodo][0]=x;
            }
        }
        if(!vis[x]){
            st[x][0]=nodo;
            dist[x]=dist[nodo]+1;
            dfs1(x,nodo);
        }
    }
    if(cc[nodo]==-1){
        cc[nodo]=lib++;
        if(supp.size()>0){
            supp.push_back(p);
            for(int x:supp){
                cc[x]=cc[nodo];
            }
        }
    }
    if(nodo!=0)adj2[st[nodo][0]].push_back(nodo);
}

void dfs2(int nodo){
    Tin[nodo]=tempo++;
    for(int i=1;i<20;i++){
        st[nodo][i]=st[st[nodo][i-1]][i-1];
    }
    for(int x:adj2[nodo]){
        dist[x]=dist[nodo]+1;
        dfs2(x);
    }
    Tout[nodo]=tempo++;
}

bool is_in(int a,int b){
    if(Tin[a]<=Tin[b]&&Tout[b]<=Tout[a])return true;
    return false;
}
int lca(int a,int b){
    if(is_in(a,b))return dist[b]-dist[a];
    if(is_in(b,a))return dist[a]-dist[b];
    int ma=a,mb=b;
    for(int i=19;i>=0;i--){
        if(!is_in(st[a][i],b))a=st[a][i];
    }
    int lc=st[a][0];
    for(int i=19;i>=0;i--){
        if(!is_in(st[b][i],lc))b=st[b][i];
    }
    if(cc[a]==cc[b])return dist[ma]+dist[mb]-2*dist[lc]-1;
    return dist[ma]+dist[mb]-2*dist[lc];
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0,0);
    dfs2(0);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }

}