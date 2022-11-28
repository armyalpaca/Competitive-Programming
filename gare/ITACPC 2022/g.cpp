#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define mod 1000000007
typedef long long ll;
vector<ll>ar(MAXN);
ll dp[MAXN];
struct nodo{
    nodo* l=NULL;
    nodo* r=NULL;
    ll v=0;
};

nodo *st;
void update(ll l,ll r,ll pos,ll v,nodo *a){
    if(l==r){
        a->v=v;
        return;
    }
    //cout<<l<<" "<<r<<endl;
    ll mid=(l+r)/2;
    if(a->l==NULL)a->l=new nodo;
    if(a->r==NULL)a->r=new nodo;
    if(pos<=mid)update(l,mid,pos,v,a->l);
    else update(mid+1,r,pos,v,a->r);
    a->v=max(a->l->v,a->r->v);
}

ll getmin(ll l,ll r,ll ql,ll qr,nodo *a){
    if(a==NULL)return 0;
    if(l>=ql&&r<=qr)return a->v;
    if(ql>r||qr<l)return 0;
    ll mid=(l+r)/2;
    //cout<<l<<" "<<r<<endl;
    return max(getmin(l,mid,ql,qr,a->l),getmin(mid+1,r,ql,qr,a->r));
}
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>ar[i];
        ar[i]+=ar[i-1];
    }
    int low=0;
    st=new nodo;
    update(0,1e15,0,0,st);
    for(int i=1;i<=N;i++){
        ll tmp=getmin(0,1e15,0,ar[i],st);
        dp[i]=ar[i]-tmp;
        update(0,1e15,dp[i]+ar[i],ar[i],st);

    }
    long long ris=1e18;
    for(int i=1;i<=N;i++){
        ris=min(ris,max(dp[i],ar[N]-ar[i]));
    }
    cout<<ris<<"\n";
   
}
