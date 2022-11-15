#include <bits/stdc++.h>
using namespace std;
#pragma once
#define mod 1000000007
vector<vector<long long> >mmultiply(vector<vector<long long> >&a,vector<vector<long long> >&b,int sz){
    vector<vector<long long> >ris(sz,vector<long long>(sz,0));
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            for(int k=0;k<sz;k++){
                ris[i][j]+=a[i][k]*b[k][j];
                ris[i][j]%=mod;
            }
        }
    }
    return ris;
}
vector<vector<long long> >mexp(vector<vector<long long> >mat,int e){
    int sz=mat.size();
    vector<vector<long long> >supp(sz,vector<long long>(sz,0));
    for(int i=0;i<sz;i++)supp[i][i]=1;
    for(int i=30;i>=0;i--){
        supp=mmultiply(supp,supp,sz);
        if(e&(1<<i)){
            supp=mmultiply(supp,mat,sz);
        } 
    }
    return supp;
}