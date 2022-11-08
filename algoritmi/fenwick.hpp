#include <bits/stdc++.h>
using namespace std;
#pragma once

class FenwickTree
{
    int n;
    vector<long long>ft;
    void update(int pos,long long val){
        for(int i=pos;i<=n;i+=i&(-i)){
            ft[i]+=val;
        }
    }
    long long getSum(int pos){
        long long ris=0;
        for(int i=pos;i>0;i-=i&(-i)){
            ris+=ft[i];
        }
        return ris;
    }
    public:

    FenwickTree(int n){
        this->n=n;
        ft.resize(n+1,0);
    }
    FenwickTree(vector<long long>ar){
        this->n=ar.size()+1;
        ft.resize(n+1,0);
        for(int i=1;i<=n;i++){
            update(i,ar[i-1]);
        }
    }
    FenwickTree(vector<int>ar){
        this->n=ar.size()+1;
        ft.resize(n+1,0);
        for(int i=1;i<=n;i++){
            update(i,ar[i-1]);
        }
    }


    long long getSum(int l,int r){
        return getSum(r)-getSum(l-1);
    }
    void changeValue(int pos,long long val){
        update(pos,-getSum(pos,pos));
        update(pos,val);
    }
    void addValue(int pos,long long val){
        update(pos,val);
    }
    
};