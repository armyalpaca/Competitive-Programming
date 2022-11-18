#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M,S,T;
    cin>>N>>M>>S>>T;
    vector<bool>vis(N+1,false);
    vector<int>conta(N+1,0);
    vector<vector<int> >adj(N+1);
    queue<int>coda;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    coda.push(T);
    vis[T]=1;
    while(!coda.empty()){
        int nodo=coda.front();
        coda.pop();
        for(int x:adj[nodo]){
            if(!vis[x]){
                conta[x]++;
                if(conta[x]>=(adj[x].size()+1)/2){
                    coda.push(x);
                    vis[x]=1;
                }
            }
        }
    }
    cout<<(vis[S]?"leave":"stay")<<endl;
}