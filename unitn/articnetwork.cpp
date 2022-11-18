#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
int N,S;
vector<array<double,2> >ar(MAXN);
vector<bool>vis(MAXN);
double dist(int i,int j){
    return sqrt((ar[i][0]-ar[j][0])*(ar[i][0]-ar[j][0])+(ar[i][1]-ar[j][1])*(ar[i][1]-ar[j][1]));
}
void dfs(int nodo,double d){
    vis[nodo]=1;
    for(int i=0;i<N;i++){
        if(!vis[i]&&dist(nodo,i)<d)dfs(i,d);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>S>>N;
        for(int i=0;i<N;i++){
            cin>>ar[i][0]>>ar[i][1];
        }
        double low=0,high=2e9;
        
        while(low+0.00001<high){
            double mid=(low+high)/2;
            int conta=0;
            fill(vis.begin(),vis.end(),false);
            for(int i=0;i<N;i++){
                if(!vis[i]){
                    dfs(i,mid);
                    conta++;
                }
            }
            //cout<<mid<<" "<<conta<<"\n";
            if(conta<=S){
                high=mid;
            }else{
                low=mid;
            }
        }
        cout<<fixed<<setprecision(2)<<low<<"\n";
    }
    

}