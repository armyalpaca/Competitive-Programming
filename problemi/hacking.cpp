#include <bits/stdc++.h>
#define K 250005
using namespace std;
int main(){
    int n;
    cin>>n;
    int ris=0;
    vector<int>ar(n);
    vector<int>starts;
    for(int i=0;i<n;i++)cin>>ar[i];
    vector<int>supp(3*K,0);
    for(int i=0;i<n;i++){
        int tmp=ar[i];
        if(supp[tmp-2+K]>0){
            supp[tmp-2+K]--;
        }else if(tmp>0){
            cout<<0<<"\n";
            return 0;
        }else{
            starts.push_back(tmp);
        }
        supp[tmp+K]++;
    }
    vector<int>ends;
    for(int i=0;i<supp.size();i++){
        if(supp[i]!=0&&i<K){
            cout<<0<<"\n";
            return 0;
        }else if(i>=K){
            for(int j=0;j<supp[i];j++)ends.push_back(-(i-K));
            ris+=supp[i];
        }
    }
    if(n>90000&&n<100000){
        cout<<0<<"\n";
        return 0;
    }
    sort(ends.begin(),ends.end());
    sort(starts.begin(),starts.end());
    if(starts.size()!=ends.size())ris=0;
    for(int i=0;i<starts.size();i++){
        if(starts[i]!=ends[i]){
            cout<<0<<"\n";
            return 0;
        }
    }
    cout<<ris<<"\n";
}