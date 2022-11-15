#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct nodo
    {
        long long int somma,prefix,suffix,massimo;
        nodo()
        {
            prefix=suffix=massimo=-2e9;
            somma=-2e9;
        }
    };
class stt{

    
    public:
    vector<nodo>st;
    vector<nodo>ar;
    nodo unisci(nodo leftChild, nodo rightChild)
    {
        nodo parentNode;
        parentNode.prefix = max(leftChild.prefix,
                                    leftChild.somma +
                                    rightChild.prefix);

        parentNode.suffix = max(rightChild.suffix,
                                    rightChild.somma +
                                    leftChild.suffix);

        parentNode.somma = leftChild.somma +
                            rightChild.somma;

        parentNode.massimo = max({leftChild.massimo,
                                        rightChild.massimo,
                                        leftChild.suffix +
                                        rightChild.prefix});

        return parentNode;
    }
    int getmid(int a,int b)
    {
        return (a+b)/2;
    }
    nodo build(int left_i,int right_i,int indice)
    {
        if(left_i==right_i)return st[indice]=ar[left_i];
        int mid=getmid(left_i,right_i);
        nodo tmp1=build(left_i,mid,indice*2+1);
        nodo tmp2=build(mid+1,right_i,indice*2+2);
        return st[indice]=unisci(tmp1,tmp2);
    }
    void update(int left_i,int right_i,int indice,int newval,int pos)
    {
        if(left_i>pos||right_i<pos)return;
        if(left_i==right_i&&left_i==pos)
        {
            st[indice].massimo=newval;
            st[indice].prefix=newval;
            st[indice].suffix=newval;
            st[indice].somma=newval;
            return;
        }
        int mid=getmid(left_i,right_i);
        update(left_i,mid,indice*2+1,newval,pos);
        update(mid+1,right_i,indice*2+2,newval,pos);
        nodo tmp1=st[indice*2+1];
        nodo tmp2=st[indice*2+2];
        st[indice]=unisci(tmp1,tmp2);
        return ;
    }
    nodo getmin(int left_i,int right_i,int indice,int query_left,int query_right)
    {
        if(left_i>query_right||right_i<query_left)
        {
            nodo tmp;
            return tmp;
        }
        if(left_i>=query_left&&right_i<=query_right)
            return st[indice];
        int mid=getmid(left_i,right_i);
        nodo tmp1=getmin(left_i,mid,indice*2+1,query_left,query_right);
        nodo tmp2=getmin(mid+1,right_i,indice*2+2,query_left,query_right);
        return unisci(tmp1,tmp2);
    }
};

int main()
{
    int n,q;
    stt t1,t2;
    cin>>n>>q;
    vector<int>ar(n);
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    vector<nodo>at1(n),at2(n);
    nodo supp;

    for(int i=0;i<n;i++){
       at1[i].massimo=at1[i].prefix=at1[i].somma=at1[i].suffix=ar[i]*(i%2==0?1:-1);
       at2[i].massimo=at2[i].prefix=at2[i].somma=at2[i].suffix=ar[i]*(i%2==1?1:-1);
    }
    t1.ar=at1;
    t1.st.resize(4*n);
    t2.st.resize(4*n);
    t2.ar=at2;
    t1.build(0,at1.size()-1,0);
    t2.build(0,at2.size()-1,0);
    //cout<<"ok"<<endl;
    int a,b,c;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b>>c;
        if(a==1){
            t1.update(0,n-1,0,c*((b-1)%2==0?1:-1),b-1);
            t2.update(0,n-1,0,c*((b-1)%2==1?1:-1),b-1);
        }else{
            cout<<max(t1.getmin(0,n-1,0,b-1,c-1).massimo,t2.getmin(0,n-1,0,b-1,c-1).massimo)<<"\n";
        }
    }
    return 0;
}