#include <bits/stdc++.h>
using namespace std;
string mat[100];
bool vis[100][100];
array<int,2> parent[100][100];
int dist[100][100];
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
int main(){
    ifstream cin("input.txt");
    int n=0;
    array<int,2>start,end;
     queue<array<int,2> >coda;
    while(cin>>mat[n++]){
        for(int i=0;i<mat[n-1].size();i++){
            if(mat[n-1][i]=='S'){
                mat[n-1][i]='a';
            }
            if(mat[n-1][i]=='a'){
                vis[n-1][i]=1;
                coda.push({n-1,i});
            }
            if(mat[n-1][i]=='E'){
                end={n-1,i};
            }
        }
    }

    n--;
    while(!coda.empty()){
        int x=coda.front()[0],y=coda.front()[1];
        //cout<<x<<" "<<y<<"\n";
        coda.pop();
        for(int i=0;i<4;i++){
            int px=x+mx[i],py=y+my[i];
            if(px<0||px>=n||py<0||py>=mat[0].size()||vis[px][py])continue;
            bool ok=false;
            if(mat[x][y]=='S'){
                ok=mat[px][py]=='a';
            }else if(mat[px][py]=='E'){
                ok=mat[x][y]=='z';
            }else{
                ok=mat[px][py]<=mat[x][y]+1;
            }
            if(ok){
                coda.push({px,py});
                vis[px][py]=1;
                dist[px][py]=dist[x][y]+1;
            }

        }
        
    }
    cout<<dist[end[0]][end[1]]<<"\n";


}