#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
vector<array<int,2> >st(4*MAXN);
vector<int>ar(MAXN);
void build(int i,int l,int r){
    if(l==r){
        st[i]={ar[l]+l,ar[l]-l};
        return;
    }
    int mid=(l+r)/2;
    build(i*2+1,l,mid);build(i*2+2,mid+1,r);
    st[i][0]=min(st[i*2+1][0],st[i*2+2][0]);
    st[i][1]=min(st[i*2+1][1],st[i*2+2][1]);
}
void up(int i,int l,int r,int pos,int val){
    if(l==r){
        st[i]={val+l,val-l};
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)up(i*2+1,l,mid,pos,val);
    else up(i*2+2,mid+1,r,pos,val);
    st[i][0]=min(st[i*2+1][0],st[i*2+2][0]);
    st[i][1]=min(st[i*2+1][1],st[i*2+2][1]);
}
int getmin(int i,int l,int r,int ql,int qr,bool a){
    if(l>=ql&&r<=qr)return st[i][a];
    if(l>qr||r<ql)return 2e9;
    int mid=(l+r)/2;
    return min(getmin(i*2+1,l,mid,ql,qr,a),getmin(i*2+2,mid+1,r,ql,qr,a));
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>ar[i];
    build(0,0,n-1);
    //for(int i=0;i<n;i++)cout<<getmin(0,0,n-1,i,i,0)<<" | "<<getmin(0,0,n-1,i,i,1)<<"\n";
    while(q--){
        int tipo;
        cin>>tipo;
        if(tipo==1){
            int a,b;
            cin>>a>>b;
            a--;
            up(0,0,n-1,a,b);
        }else{
            int k;
            cin>>k;
            k--;
            cout<<min(k+getmin(0,0,n-1,0,k,1),-k+getmin(0,0,n-1,k,n-1,0))<<"\n";
        }
    }
}