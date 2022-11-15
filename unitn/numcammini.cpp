#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
     int N,M,S,D;
     cin>>N>>M>>S>>D;
     vector<vector<int> >adj(N);
     vector<int>dist(N),conta(N,0);
     vector<bool>vis(N,false);
     queue<int>coda;
     for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
     }
     coda.push(S);
     vis[S]=1;
     dist[S]=0;
     conta[S]=1;
     while(!coda.empty()){
        int nodo=coda.front();
        coda.pop();
        for(int x:adj[nodo]){
            if(!vis[x]){
                dist[x]=dist[nodo]+1;
                vis[x]=1;
                coda.push(x);
                conta[x]=conta[nodo];
            }else if(dist[x]==dist[nodo]+1){
                conta[x]+=conta[nodo];
            }
        }
     }
     cout<<dist[D]<<" "<<conta[D]<<"\n";
}