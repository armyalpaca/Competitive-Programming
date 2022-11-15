#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P){
  vector<pair<long long,int> >supp;
  for(int i=0;i<M;i++){
    supp.push_back({P[i],i});
  }
  sort(supp.begin(),supp.end());
  vector<long long>ris(M);
  int j=0;
  long long somma=0;
  long long tot=0;
  for(int i=0;i<T;i++){
    somma+=i*S[i];
    while (j<M&&somma>supp[j].first) {
      long long tmp=somma-i*S[i];
      long long tmp2=supp[j].first-tmp;
      ris[supp[j].second]=tot+tmp2/i;
      j++;
    }
    tot+=S[i];
  }
  while (j<M) {
    ris[supp[j].second]=tot;
    j++;
  }
  return ris;

}