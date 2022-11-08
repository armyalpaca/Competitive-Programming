#include <bits/stdc++.h>
#define K 300005
using namespace std;
int main(){
    int n;
    cin>>n;
    int ris=0;
    vector<int>ar(n);
    for(int i=0;i<n;i++)cin>>ar[i];
    vector<int>supp(3*K,0);
    for(int i=0;i<n;i++){
        int tmp=ar[i];
        if(supp[tmp-2+K]>0){
            supp[tmp-2+K]--;
        }else if(tmp>0){
            cout<<0<<"\n";
            return 0;
        }
        supp[tmp+K]++;
    }
    for(int i=0;i<supp.size();i++){
        if(supp[i]!=0&&i<K){
            cout<<0<<"\n";
            return 0;
        }else if(i>=K){
            ris+=supp[i];
        }
    }
    cout<<ris<<"\n";
}