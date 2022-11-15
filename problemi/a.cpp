#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAXN 1000000
typedef long long ll;
 
ll fxp(ll b,ll e){
    if(e==0)return 1;
    ll tmp=fxp(b,e/2);
    tmp=(tmp*tmp);
    if(e%2)tmp=(tmp*b);
    return tmp;
}
vector<int>st(MAXN);
vector<int>ar(MAXN);
void build(int i,int l,int r){
    if(l==r){
        st[i]=l;
        return;
    }
    int mid=(l+r)/2;
    build(i*2+1,l,mid);
    build(i*2+2,mid+1,r);
    if(ar[st[i*2+1]]>=ar[st[i*2+2]]){
        st[i]=st[i*2+1];
    }
    else st[i]=st[i*2+2];
}
int getmax(int i,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr)return st[i];
    if(l>qr||r<ql)return -1;
    int mid=(l+r)/2;
    int a=getmax(i*2+1,l,mid,ql,qr),b=getmax(i*2+2,mid+1,r,ql,qr);
    if(a==-1)return b;
    if(b==-1)return a;
    if(ar[a]>=ar[b])return a;
    return b;
}
int n;
map<array<int,3>,long long>dp2;
long long f(int l,int r,int mas){
    if(l==r&&mas>0)return mas;  
    if(l>r)return 1;
    if(mas<=0)return 0;
    if(dp2[{l,r,mas}]!=0)return dp2[{l,r,mas}];
    vector<pair<int,int> >supp;
    int tmp=l;
    while (tmp<=r)
    {
        int prossimo=getmax(0,0,n-1,tmp,r);
        supp.push_back({tmp,prossimo-1});
        tmp=prossimo+1;
    }
    long long ris2=1;
    vector<vector<long long> >dp(supp.size()+1,vector<long long>(mas+2,0));
    for(int i=mas;i>0;i--){
        dp[1][i]=f(supp[0].first,supp[0].second,i-1);
        dp[1][i]+=dp[1][i+1];
        dp[1][i]%=mod;
    }
    for(int i=2;i<=supp.size();i++){
        for(int j=mas;j>0;j--){
            dp[i][j]=dp[i-1][j]*f(supp[i-1].first,supp[i-1].second,j-1);
            //cout<<supp[i-1].first<<" "<<supp[i-1].second<<" "<<j<<" "<<dp[i][j]<<"\n";
            dp[i][j]+=dp[i][j+1];
            dp[i][j]%=mod;
        }
    }
    //cout<<l<<" "<<r<<" "<<mas<<" "<<dp[supp.size()][0]<<"\n";
    return dp2[{l,r,mas}]=dp[supp.size()][1];
}
int main(){
    ifstream cin("input.txt");
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>ar[i];
        build(0,0,n-1);
        cout<<f(0,n-1,m)<<"\n";
        dp2.clear();
    }
}