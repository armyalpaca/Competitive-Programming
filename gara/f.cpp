#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>ar(n+1);
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            ar[b]=c;
        }else{
            vector<ll>pref1(c+1,0),pref2(c+1,0);
            pref1[b]=ar[b];
            ll massimo=ar[b];
            for(int i=b+2;i<=c;i+=2){
                pref1[i]=ar[i]-ar[i-1]+pref1[i-2];
                pref1[i]=max(pref1[i],(long long)ar[i]);
                massimo=max(massimo,pref1[i]);
            }
            if(c>b){
                pref2[b+1]=ar[b+1];
                massimo=max(massimo,(long long)ar[b+1]);
                for(int i=b+3;i<=c;i+=2){
                    pref2[i]=ar[i]-ar[i-1]+pref2[i-2];
                    pref2[i]=max(pref2[i],(long long)ar[i]);
                    massimo=max(massimo,pref2[i]);
                }
            }
            cout<<massimo<<"\n";

        }

    }
}