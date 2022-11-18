#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>ar(n+1);
    set<pair<int,int> >ok;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        if(ar[i]!=0)ok.insert({-ar[i],i});
    }
    vector<pair<int,int> >ris;
    while(!ok.empty()){
        auto a=*ok.begin();
        ok.erase(ok.begin());
        set<pair<int,int> >da_inserire;
        while(a.first<0){
            if(ok.empty())break;
            auto b=*ok.begin();
            ok.erase(ok.begin());
            b.first++;
            a.first++;
            ris.push_back({a.second,b.second});       
            da_inserire.insert(b);     
        }
        if(a.first<0){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        for(auto x:da_inserire){
            if(x.first<0)ok.insert(x);
        }
    } 
    cout<<ris.size()<<"\n";
    for(auto x:ris)cout<<x.first<<" "<<x.second<<"\n";
}