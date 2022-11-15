 #include <bits/stdc++.h>
 using namespace std;
 #define MAXN 1000005
 vector<int>st(4*MAXN,2e9);
 int query(int i,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr)return st[i];
    if(l>qr||r<ql)return 2e9;
    int mid=(l+r)/2;
    return min(query(i*2+1,l,mid,ql,qr),query(i*2+2,mid+1,r,ql,qr));
 }
 void update(int i,int l,int r,int pos,int val){
    if(l==r){
        st[i]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)update(i*2+1,l,mid,pos,val);
    else update(i*2+2,mid+1,r,pos,val);
    st[i]=min(st[i*2+1],st[i*2+2]);
 }
 int salta(int N, vector<int> S, vector<int> A, vector<int> B){
	update(0,0,N,N,0);
    for(int i=N-1;i>=0;i--){
        int tmp=query(0,0,N,i+A[i],i+B[i]);
        tmp=max(tmp,S[i]);
        update(0,0,N,i,tmp);
    }
    return query(0,0,N,0,0);
 }