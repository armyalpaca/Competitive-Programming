#include <bits/stdc++.h>
using namespace std;
map<string,string>parent;
map<string,vector<string> >adj;
map<string,long long>sz;
long long ris=1e9,spazio=0;
void dfs(string nodo){
    for(auto x:adj[nodo]){
        dfs(x);
        sz[nodo]+=sz[x];
    }
    if(sz[nodo]>=spazio)ris=min(ris,sz[nodo]);
}
int main(){
    ifstream cin("input.txt");
    int n;
    cin>>n;
    string cur="";
    while(n--){
        string s1,s2,s3;
        cin>>s1;
        if(s1=="$"){
            cin>>s2;
            if(s2=="ls"){

            }else if(s2=="cd"){
                cin>>s3;
                if(s3=="/"){
                    cur="/";
                }else if(s3==".."){
                    cur=parent[cur];
                }else{
                    cur+="/"+s3;
                }
            }
        }else if(s1=="dir"){
            cin>>s2;
            parent[cur+"/"+s2]=cur;
            adj[cur].push_back(cur+"/"+s2);
        }else {
            long long tmp=0;
            for(int i=0;i<s1.size();i++){
                tmp*=10;
                tmp+=s1[i]-'0';
            }
            spazio+=tmp;
            sz[cur]+=tmp;
            cin>>s2;
        }
    }
    spazio=70000000-spazio;
    spazio=30000000-spazio;
    dfs("/");

    cout<<ris<<"\n";
}