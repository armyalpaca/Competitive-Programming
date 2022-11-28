#include <bits/stdc++.h>
using namespace std;
#define MAXN 505

char mat[502][502];
vector<set<int> >adj(MAXN);
int G=1;
vector<int>r1(MAXN),r2(MAXN);
vector<bool>vis(MAXN;
void dfs(int nodo,int gruppo,int accesso){
    vis[nodo]=1;
    r1[nodo]=gruppo;
    r2[nodo]=accesso;
    bool primo=true;
    for(int x:adj[nodo]){
        if(primo){
            dfs(x,gruppo,accesso+1);
            primo=false;
        }else{
            dfs(x,++G,1);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    map<string,int>mappa;
    int cc=1;
    vector<int>C(m);
    for(int i=0;i<m;i++){
        string tmp="";
        for(int j=0;j<n;j++){
            tmp+=mat[j][i];
        }
        if(mappa[tmp]==0){
            mappa[tmp]=cc++;
        }
        C[i]=mappa[tmp];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(C[i]==C[j])continue;
            bool ok=true;
            for(int k=0;k<n;k++){
                if(mat[k][i]=='0'&&mat[k][j]=='1'){
                    ok=false;
                    break;
                }
            }
            if(ok){
                adj[C[i]].insert(C[j]);
            }
        }
    }
}