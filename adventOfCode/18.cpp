#include <bits/stdc++.h>
using namespace std;
set<array<int,3> >ok;
set<array<int,3> >vis;
int ris=0;
void dfs(array<int,3>nodo){
    if(nodo[0]<-1||nodo[1]<-1||nodo[2]<-1)return;
    if(nodo[0]>21||nodo[1]>21||nodo[2]>21)return;
    //cout<<nodo[0]<<" "<<nodo[1]<<" "<<nodo[2]<<" "<<ris<<"\n";
    vis.insert(nodo);
    for(int i=0;i<3;i++){
        for(int j=-1;j<2;j+=2){
            array<int,3>tmp=nodo;
            tmp[i]+=j;
            if(ok.count(tmp))ris++;
            else if(!vis.count(tmp))dfs(tmp);
        }
    }
}
int main(){
    ifstream cin("input.txt");
    
    int a,b,c;
    char d;
    while(cin>>a>>d>>b>>d>>c){
        ok.insert({a,b,c});
    }
    dfs({-1,-1,-1});
    cout<<ris<<"\n";
}