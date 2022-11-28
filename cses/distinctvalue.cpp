#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

struct node{
    int v=0;
    node *l=NULL;
    node *r=NULL;
};


node *Versioni[MAXN];


void update(int l,int r,int pos,int vers,node *a,node *b){
    if(l==r){
        a->v = b->v +1;
        return;
    }
    int mid=(l+r)/2;
    if(b->r==NULL)b->r=new node;
    if(b->l==NULL)b->l=new node;
    if(pos<=mid){
        a->r=b->r;
        a->l=new node;
        update(l,mid,pos,vers,a->l,b->l);
    }else{
        a->l=b->l;
        a->r=new node;
        update(mid+1,r,pos,vers,a->r,b->r);
    }
    a->v=a->l->v+a->r->v;
}

int countg(int l,int r,int pos,node *a){
    if(a==NULL)return 0;
    if(l>=pos)return a->v;
    if(r<pos)return 0;
    int mid=(l+r)/2;
    return countg(l,mid,pos,a->l)+countg(mid+1,r,pos,a->r);
}


vector<int>ar(MAXN),nex(MAXN);
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    unordered_map<int,int>mappa;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        mappa[ar[i]]=n+1;
    }
    
    for(int i=n;i>=0;i--){
        nex[i]=mappa[ar[i]];
        mappa[ar[i]]=i;
    }

    Versioni[0]=new node;
    for(int i=1;i<=n;i++){
        Versioni[i]=new node;
        update(0,1e9,nex[i],i,Versioni[i],Versioni[i-1]);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<countg(0,1e9,b+1,Versioni[b])-countg(0,1e9,b+1,Versioni[a-1])<<"\n";
    }
}