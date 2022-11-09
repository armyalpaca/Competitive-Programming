#include <iostream>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> cucina(int N, int K, int X, vector<int> H){
    vector<int>ar(X+1,0);
    for(int i=0;i<N;i++){
        ar[H[i]]++;
    }
    vector<int>supp(X,-1);
    int placed=0;
    deque<int>coda;
    for(int i=0;i<X;i++){
        while(ar[i]--){
            coda.push_back(i);
        }
        if(coda.size()>0){
            supp[i]=coda.front();
            coda.pop_front();
        }
    }
    vector<int>cnt(X+1,0);
    vector<int>ris(X);
    int j=coda.size();
    for(int i=X-1;i>=0;i--){
        while(!coda.empty()&&coda.back()>i){
            coda.pop_back();
            if(j>coda.size())j=coda.size();
        }
        if(supp[i]!=-1){
            coda.push_front(supp[i]);
            j++;
        }
        while(j>0&&coda[j-1]>=i){
            j--;
        }
        int conta=coda.size()-j;
        conta=min(conta,X-i);
        ris[i]=min(K,conta);
        if(i!=X-1)ris[i]+=ris[i+1];
        ris[i]=min(ris[i],X-i);
    }
    return ris;
}

int main() {
    // se preferisci leggere e scrivere da file ti basta decommentare le seguenti due righe:
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, K, X;
    cin >> N >> K >> X;

    vector<int> H(N);
    for (int& h : H) {
        cin >> h;
    }

    vector<int> res = cucina(N, K, X, move(H));
    for (int r : res) {
        cout << r << ' ';
    }
    cout << endl;

    return 0;
}