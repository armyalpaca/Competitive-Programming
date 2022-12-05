#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string>ar={"DLVTMHF","HQGJCTNP","RSDMPH","LBVF","NHGLQ","WBDGRMP","GMNRCHLQ","CLW","RDLQJZMT"};
    ifstream cin("input.txt");
    string s;
    int a,b,c;
    while(cin>>s>>a>>s>>b>>s>>c){
        b--;c--;
        s=ar[b].substr(ar[b].size()-a);
        ar[b]=ar[b].substr(0,ar[b].size()-a);
        ar[c]+=s;
    }
    for(int i=0;i<9;i++){
        cout<<ar[i][ar[i].size()-1];
    }
    cout<<"\n";
}