#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>ar(N);
    for(int i=0;i<N;i++)cin>>ar[i];
    vector<int>fgl(N,-1),fgr(N,N);
    vector<int>fel(N,-1),fer(N,N);
    stack<int>s;
    for(int i=0;i<N;i++){
        while(!s.empty()&&ar[s.top()]<ar[i]){
            s.pop();
        }
        if(!s.empty()&&ar[s.top()]==ar[i]){
            fel[i]=s.top();
            while(!s.empty()&&ar[s.top()]==ar[i]){
                s.pop();
            }   
        }
        if(!s.empty()){
            fgl[i]=s.top();
        }
        s.push(i);
    }
    while(!s.empty())s.pop();

    for(int i=N-1;i>=0;i--){
        while(!s.empty()&&ar[s.top()]<ar[i]){
            s.pop();
        }
        if(!s.empty()&&ar[s.top()]==ar[i]){
            fer[i]=s.top();
            while(!s.empty()&&ar[s.top()]==ar[i]){
                s.pop();
            }   
        }
        if(!s.empty()){
            fgr[i]=s.top();
        }
        s.push(i);
    }
    int ris=0;
    for(int i=0;i<N;i++){
        if(fel[i]==-1){
            fel[i]=i;
            continue;
        }
        int uguale=fel[i]=fel[fel[i]];
        int maggiore=fgl[i];
        if(maggiore>uguale){
            fel[i]=i;
            continue;
        }
        int l1=fgl[uguale]+1;
        int l2=fgr[i]-1;
        int L1=max(l1,uguale-(l2-1-uguale));
        int L2=min(l2,i+(i-l1-1));
        ris=max(ris,L2-L1+1);

    }
    cout<<ris<<"\n";
}