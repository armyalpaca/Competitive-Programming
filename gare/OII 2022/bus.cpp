#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int pianifica(int N, int L, vector<vector<int>> F){
  vector<vector<int> >dist(L+1);
  vector<vector<bool> >vis(L+1);
  vector<vector<pair<int,int> > >adj(N);
  for(int i=0;i<L;i++){
    dist[i].resize(F[i].size(),1e9);
    vis[i].resize(F[i].size(),false);
    for(int j=0;j<F[i].size();j++){
      adj[F[i][j]].push_back({i,j});
    }
  }
  dist[L].resize(N,1e9);
  vis[L].resize(N,false);
  dist[L][0]=0;
  priority_queue<array<int,3> >coda;
  coda.push({0,L,0});
  while (!coda.empty()) {
    int linea=coda.top()[1];
    int fermata=coda.top()[2];
    //cout<<linea<<" "<<fermata<<" "<<dist[linea][fermata]<<"\n";
    coda.pop();
    if(vis[linea][fermata])continue;
    vis[linea][fermata]=1;
    if(linea==L){
      for(auto x:adj[fermata]){
        if(dist[x.first][x.second]>dist[linea][fermata]+1){
          dist[x.first][x.second]=dist[linea][fermata]+1;
          coda.push({-dist[x.first][x.second],x.first,x.second});
        }
      }
    }else{
      if(dist[L][F[linea][fermata]]>dist[linea][fermata]){
        dist[L][F[linea][fermata]]=dist[linea][fermata];
        coda.push({-dist[L][F[linea][fermata]],L,F[linea][fermata]});
      }
      if(fermata!=F[linea].size()-1&&dist[linea][fermata+1]>dist[linea][fermata]){
        dist[linea][fermata+1]=dist[linea][fermata];
        coda.push({-dist[linea][fermata+1],linea,fermata+1});
      }
    }
  }
  if(dist[L][N-1]==1e9)return -1;
  return dist[L][N-1]-1;
}