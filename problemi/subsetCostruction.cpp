#include <bits/stdc++.h>
using namespace std;
map<string,int>pos;
vector<vector<pair<int,string> > >adj;
int main(){
    map<string,vector<int> >mappa;
    vector<array<string,2> >edges;
    string supp;
    cin>>supp;
    while(supp!="{"){
        cin>>supp;
    }
    while(true){
        string a,tmp,b,c;
        cin>>a;
        if(a=="}")break;
        cin>>tmp>>b>>c;
        c=c.substr(8,1);
        mappa[a].push_back(edges.size());
        mappa[b].push_back(1);
        mappa[b].pop_back();
        edges.push_back({b,c});
    }
    int postmp=0;
    for(auto v:mappa){
        pos[v.first]=postmp++;
    }
    for(auto v:mappa){
        for(auto x:v.second){
            adj[pos[v.first]].push_back({pos[edges[x][0]],edges[x][1]});
        }
    }



}