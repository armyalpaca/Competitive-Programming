#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define mod 666013
#define int long long
typedef long long ll;
int K,X;
vector<ll>pot(MAXN);
long long f(int cifre){
    return (pot[X/2-cifre/2]+pot[X/2+cifre/2-1])%mod;
}
long long fxp(ll b,int e){
    if(e==0)return 1;
    ll tmp=fxp(b,e/2);
    tmp=(tmp*tmp);
    if(e%2)tmp=tmp*b;
    return tmp;
}
long long fxp2(ll b,int e){
    if(e==0)return 1;
    ll tmp=fxp2(b,e/2);
    tmp=(tmp*tmp)%mod;
    if(e%2)tmp=(tmp*b)%mod;
    return tmp;
}
vector<ll>dp(MAXN,0);
signed main(){
    pot[0]=1;
    for(int i=1;i<MAXN;i++){
        pot[i]=(pot[i-1]*10)%mod;
    }
    
    cin>>K>>X;
    ll conta=K;
    ll somma=0;
    dp[0]=0;
    for(int i=2;i<=X;i+=2){
        dp[i]=10*dp[i-2];
        dp[i]%=mod;
        for(int j=0;j<10;j++){
            dp[i]+=f(i)*j*fxp2(10,(i-2)/2);
            dp[i]%=mod;
        }
    }
    for(int cifre=X;cifre>0;cifre-=2){
        for(int i=0+(X==cifre);i<10;i++){
            if(conta==0)break;
            if(cifre>16){
                somma+=f(cifre)*i*conta;
                somma%=mod;
                break;
            }else{
                ll tmp=fxp(10,(cifre-2)/2);
                if(tmp>=conta){
                    somma+=f(cifre)*i*conta;
                    somma%=mod;
                    break;
                }else{
                    conta-=tmp;
                    somma+=f(cifre)*i*tmp+dp[cifre-2];
                    somma%=mod;
                }
            }
        }
    }
    cout<<somma%mod<<"\n";
}   