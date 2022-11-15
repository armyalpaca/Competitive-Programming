#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
vector<vector<int> >adj(MAXN);
int up[MAXN][25];
int tempo=0;
int Tin[MAXN],Tout[MAXN];
void dfs1(int nodo,int p){
    Tin[nodo]=tempo++;
    up[nodo][0]=p;
    for(int i=1;i<25;i++){
        up[nodo][i]=up[up[nodo][i-1]][i-1];
    }
    for(int x:adj[nodo]){
        if(x!=p)dfs1(x,nodo);
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
    for(int i=24;i>=0;i--){
        if(!is_in(up[a][i],b)){
            a=up[a][i];
        }
    }
    return up[a][0];
}
vector<vector<int> >archi(MAXN);
vector<long long>ris(MAXN,0);
vector<int>high(MAXN,1e9);
void dfs2(int nodo,int p){
    
    high[nodo]=Tin[nodo];
    for(int x:adj[nodo]){
        if(x!=p){
            dfs2(x,nodo);
            ris[nodo]+=ris[x];
            if(high[x]>Tin[nodo]){
                ris[nodo]++;
            }else if(high[x]==Tin[nodo]){
                ris[nodo]++;
            }
            high[nodo]=min(high[nodo],high[x]);
        }
    }
    for(int x:archi[nodo]){
        high[nodo]=min(high[nodo],Tin[lca(x,nodo)]);
    }
}

#define mod 1000000007
typedef long long ll;
 
ll fxp(ll b,ll e){
    if(e==0)return 1;
    ll tmp=fxp(b,e/2);
    tmp=(tmp*tmp);
    if(e%2)tmp=(tmp*b);
    return tmp;
}
int main(){
    int N,M;
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        archi[a].push_back(b);
        archi[b].push_back(a);
    }   
    dfs1(1,1);
    dfs2(1,1);
    cout<<fxp(2,ris[1])<<"\n";

} 