#include<bits/stdc++.h>
using namespace std;
class Segment{
    #define j i+i
    int K=1<<20;
    struct Nodo{
        long long s=0,m=0,v=0,t=0;
    };
    Nodo T[1<<21];
    void C(int i){
        Nodo &n=T[i],c=T[j],d=T[j+1];
        n.s=c.s+d.s,n.m=min(c.m,d.m);
    }

    void P(int l,int i){
    Nodo &n=T[i],&c=T[j],&d=T[j+1];
    if(n.t|n.v){
        if(n.t)n.s=l*n.v,n.m=n.v;
        else n.s+=l*n.v,n.m+=n.v;
        if(i<K){
        if(n.t)c.t=d.t=1,c.v=d.v=0;
        c.v+=n.v,d.v+=n.v;
        }
        n.v=n.t=0;
    }
    }
    void U(int a,int b,int l,int r,int i,long long x,int u){
    P(b-a,i);
    if(b>l&&a<r){
        if(a>=l&&b<=r){
            T[i].v=x,T[i].t=u;
            P(b-a,i);
            return;
        }
        U(a,(a+b)/2,l,r,j,x,u);
        U((a+b)/2,b,l,r,j+1,x,u);
        C(i);
    }
    }
    long long S(int a,int b,int l,int r,int i){
        P(b-a,i);
        if(b<=l||a>=r)return 0;
        if(a>=l&&b<=r)return T[i].s;
        return S(a,(a+b)/2,l,r,j)+S((a+b)/2,b,l,r,j+1);
    }
    long long M(int a,int b,int l,int r,int i){
        P(b-a,i);
        if(b<=l||a>=r)return 1e16;
        if(a>=l&&b<=r)return T[i].m;
        return min(M(a,(a+b)/2,l,r,j),M((a+b)/2,b,l,r,j+1));
    }
    long long B(int a,int b,int l,int r,int i,int x){
        P(b-a,i);
        if(b<=l||a>=r||T[i].m>x)return -1; //indice primo minore nel range [l,r]
        if(b==a+1)return a;
        int ret=B(a,(a+b)/2,l,r,j,x);
        return ret<0? B((a+b)/2,b,l,r,j+1,x):ret;
    }
    public:
    void init(vector<long long> a){
        for(int i=0;i<int(a.size());++i){
            Nodo& n=T[i+K];
            n.s=n.m=a[i];
        }
        for(int i=K-1;i>0;)C(i--);
    }
    void add(int l,int r,int x){ 
        U(0,K,l,r,1,x,0);
    }
    void set_range(int l,int r,long long x){
        U(0,K,l,r,1,x,1);
    }
    long long get_sum(int l,int r){
        return S(0,K,l,r,1);
    }
    long long get_min(int l,int r){
        return M(0,K,l,r,1);
    }
    int lower_bound(int l,int r,long long x){
        return B(0,K,l,r,1,x);
    }
    //indice destro escluso : [l,r-1]
};
