#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,L;
    cin>>N>>L;
    vector<int>l1;
    map<int,vector<int> >mappa;
    vector<pair<int,int> >l2;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        if(b==-1)l1.push_back(a);
        else mappa[b].push_back(a);
    }
    priority_queue<int>coda;
    for(int i=L-1;i>=0;i--){
        for(int x:mappa[i])coda.push(x);
        if(!coda.empty()){
            l2.push_back({coda.top(),i});
            coda.pop();
        }
    }

    sort(l2.begin(),l2.end());
    sort(l1.begin(),l1.end());
    int l=0,r=L-1;
    int ma=-1;
    int ris=0;
    while(l<=r){
        if(l1.size()==0&&l2.size()==0)break;
        if(l2.size()==0){
            ris+=l1.back();
            l1.pop_back();
            r--;
        }else if(l1.size()==0){
            ma=max(ma,l2.back().second);
            if(ma>=l){
                ris+=l2.back().first;
                l++;
            }
            l2.pop_back();
        }else{
            if(l1.back()>l2.back().first){
                ris+=l1.back();
                l1.pop_back();
                r--;
            }else{
                ma=max(ma,l2.back().second);
                if(ma>=l){
                    ris+=l2.back().first;
                    l++;
                }
                l2.pop_back();
            }
        }
    }
    cout<<ris<<"\n";
}