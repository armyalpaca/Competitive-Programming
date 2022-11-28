#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define mod 1000000007
typedef long long ll;
vector<ll>primi;
unordered_map<ll,ll>dp;
ll f(ll n){
    if(n==1)return 1;
    if(dp[n]!=0)return dp[n];
    ll ris=0;
    for(ll x:primi){
        if(n%x==0){
    
            ris+=f(n/x);
            ris%=mod;
        }
    }
    //cout<<n<<" "<<ris<<"\n";
    return dp[n]=ris;
}
int main(){
    ll N;
    cin>>N;
    for(ll i=2;i*i<=N;i++){
        if(N%i==0){
            primi.push_back(i);
            if(i*i!=N){
                primi.push_back(N/i);
            }
        }
    }

    primi.push_back(N);

    cout<<f(N)<<"\n";
}