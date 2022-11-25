#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 500005
array<int,6>archi[2*MAXM];
vector<vector<int> >adj(MAXN);
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<6;j++)cin>>archi[2*i][j];
        if(archi[2*i][2]<=archi[2*i][4]){
            adj[archi[2*i][0]].push_back(2*i);
            array<int,6>tmp=archi[2*i];
            swap(tmp[0],tmp[1]);
            archi[2*i+1]=tmp;
            adj[archi[2*i+1][0]].push_back(2*i+1);
        }
    }
    priority_queue<array<long long,2> >coda;
    vector<bool>vis(n,false);
    vector<long long>dist(n,1e18);
    vector<int>parent(n,0);
    dist[0]=0;
    coda.push({0,0});
    while(!coda.empty()){
        int nodo=coda.top()[1];
        coda.pop();
        if(vis[nodo])continue;
        vis[nodo]=1;
        for(int i:adj[nodo]){
            int dest=archi[i][1];
            if(vis[dest])continue;
            long long start;
            if(dist[nodo]<=archi[i][3])start=archi[i][3];
            else{
                long long tmp=dist[nodo]-archi[i][3];
                long long tmp1=tmp/(archi[i][4]+archi[i][5]);
                tmp%=(archi[i][4]+archi[i][5]);
                start=tmp1*(archi[i][4]+archi[i][5]);
                if(tmp+archi[i][2]>archi[i][4]){
                    start+=(archi[i][4]+archi[i][5]);
                }else{
                    start+=tmp;
                }
                start+=archi[i][3];
            }
            if(dist[dest]>start+archi[i][2]){
                parent[dest]=nodo;
                dist[dest]=start+archi[i][2];
                coda.push({-dist[dest],dest});
            }

        }
    }
    if(dist[n-1]==2e9)cout<<-1<<"\n";
    else{
        cout<<dist[n-1]<<"\n";
        vector<int>supp;
        int nodo=n-1;
        while(parent[nodo]!=nodo){
            supp.push_back(nodo);
            nodo=parent[nodo];
        }
        supp.push_back(0);
        reverse(supp.begin(),supp.end());
        for(int x:supp)cout<<x<<"\n";
    }
}