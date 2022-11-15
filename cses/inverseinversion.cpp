#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long k;
    cin>>n>>k;
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        if(r-l<=k){
            cout<<r<<" ";
            k-=r-l;
            r--;
        }else{
            cout<<l++<<" ";
        }
    }
    cout<<"\n";
}