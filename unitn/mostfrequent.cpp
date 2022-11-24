/*
Problema:
Hai un array lungo N (N<=10^5) e Q query (Q<=10^5)
Ogni query ti chiede qual'è il valore con frequenza maggiore all'interno di un intervallo (il valore che appare più volte)

Formato Input:

N Q
V[0] V[1] .... V[N-1]

l1 r1
l2 r2
...
lQ rQ

Ogni query è rappresentata da due valori l, r che sono gli estremi dell'intervallo di cui si vuole trovaro l'elemento con frequenza massima


*/


//Soluzione O((N+Q)*sqrt(N)) 
// Mo's algorithm

#include <bits/stdc++.h>
using namespace std;
struct query{//estremi dell'intervallo e id della query per capire in che ordine devo rispondere
    int l,r,id;
};
bool cmp(query a,query b){
    return a.r<b.r;
}


int main(){
    int n,q;
    cin>>n>>q;
    vector<int>ar(n);
    int k=sqrt(n);
    vector<vector<query> >queries(n/k+1);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        queries[l/k].push_back({l,r,i}); 
    }
    for(int i=0;i<queries.size();i++){
        sort(queries[i].begin(),queries[i].end(),cmp);//ordino le query nello stesso blocco con estremo destro crescente
    }

    vector<int>ris(q);//in ris[i] salvo i risultati dell'iesima query e quando li ho calcolati tutti li stampo in ordine

    
    for(int i=0;i<queries.size();i++){ //scorro ogni blocco , i blocchi sono lunghi k
        //il blocco i contiene gli elementi dall'indice i*k all'indice (i+1)*k-1
        if(queries[i].size()==0)continue;//se non ci sono query che iniziano in questo blocco passo al prossimo
        int r=(i+1)*k-1; //
        map<int,int>mappa; //mappa contiene le frequenze dei valori a destra del blocco in cui sono
        int massimo_destra=0; //valore con frequenza massima in mappa
        for(auto x:queries[i]){
            while(r<x.r){   //estendo l'intervallo fino  a x.r
                r++;
                mappa[ar[r]]++;
                if(mappa[ar[r]]>mappa[massimo_destra])massimo_destra=ar[r];
            }
            int massimo=massimo_destra;
            map<int,int>supp;//supp contiene le frequenze dei valori all'interno del blocco in cui sono
            for(int j=min(x.r,(i+1)*k-1);j>=x.l;j--){ //devo distinguere il caso in cui la mia query ha indice destro all'interno del mio blocco, per questo parto da min(x.r,(i+1)*k-1)
                supp[ar[j]]++; 
                if(supp[ar[j]]+mappa[ar[j]]>mappa[massimo]+supp[massimo]){  //supp[ar[j]]+mappa[ar[j]] indica la frequenza di ar[j] all'interno del blocco + la sua frequenza a destra del blocco
                    massimo=ar[j];
                }
            }
            ris[x.id]=massimo;
        }
        
    }
    for(int i=0;i<q;i++){
        cout<<ris[i]<<"\n";
    }
} 