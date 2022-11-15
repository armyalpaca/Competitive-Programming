#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int>nex(n+1),prev(n+1);
    for(int i=0;i<n;i++)nex[i]=i+1,prev[i]=i-1;
    int l=n-1;
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        int pr=prev[a];
        int nx=nex[b];
        if(pr!=-1){
            nex[pr]=nx;
        }
        if(nx!=n){
            prev[nx]=pr;
        }
        nex[l]=a;
        nex[b]=n;
        prev[a]=l;
        l=b;
        for(int i=0;i<n;i++)cout<<i<<": "<<prev[i]<<" "<<nex[i]<<"\n";
        cout<<"----------------\n";
    }
    string ris="";
    while(l!=-1){
        ris+=s[l];
        l=prev[l];
    }
    reverse(ris.begin(),ris.end());
    cout<<ris<<"\n";
}