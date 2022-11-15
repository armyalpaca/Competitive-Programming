#include <bits/stdc++.h>
using namespace std;
int f(long long p,long long n,map<long long,int>&dp){
    if(p>=n)return 1;
    if(dp[p]!=0)return dp[p];
    for(int i=2;i<10;i++){
        if(f(i*p,n,dp)==1){
            return dp[p]=2;
        }
    }
    return dp[p]=1;
}
int main(){
    long long n;
    while(cin>>n){
        map<long long,int>dp;
        if(f(1,n,dp)==2){
            cout<<"Stan wins.\n";
        }else{
            cout<<"Ollie wins.\n";
        }
        dp.clear();
    }
}