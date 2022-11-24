/*Problema:
    Hai un grafo con N,M<=100000 dove N e M sono il numero di nodi e di archi
    Ogni nodo ha un valore iniziale V[i]

    Devi rispondere a delle query di due tipi:
        tipo 1: trova la somma dei valori dei nodi vicini al nodo dato
        tipo 2: modifica il valore del nodo dato


    Formato Input:
    N M Q
    V[0] V[1] ... V[N-1]
    query 1 
    query 2
    ....
    query Q


    ogni query inizia con il tipo 
    query tipo 1:
        1 nodo
    query tipo 2:
        2 nodo newval
*/

/*
    Soluzione: O(Q*sqrt(M))
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<vector<int> >adj(MAXN);
vector<vector<int> >vicini_piccoli(MAXN);
vector<vector<int> >vicini_grandi(MAXN);
vector<int>V(MAXN);  //V[nodo] contiene il valore del nodo
vector<int>S(MAXN); //S[nodo] contiene la somma dei valori dei vicini piccoli di nodo
int k;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)cin>>V[i];
    k=sqrt(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int vicino:adj[i]){
            if(adj[vicino].size()>k){
                vicini_grandi[i].push_back(vicino);
            }else{
                vicini_piccoli[i].push_back(vicino);
                if(adj[i].size()>k)S[i]+=V[i];
            }
        }
    }
    while(q--){
        int tipo;
        cin>>tipo;
        if(tipo==1){//somma dei valori dei nodi vicino al nodo dato in input
            int nodo;
            cin>>nodo;
            int ris=0;
            if(adj[nodo].size()>k){//se il nodo è "grande"
                ris=S[nodo];//S[nodo]= somma dei vicini piccoli
                for(int vicino:vicini_grandi[nodo]){ //faccio la somma dei vicini grandi che sono al più sqrt(M)
                    ris+=V[vicino];
                }
            }else{ // se il nodo è "piccolo"
                //faccio la somma di tutto i valori dei nodi vicini
                for(int vicino:vicini_grandi[nodo])ris+=V[vicino];
                for(int vicino:vicini_piccoli[nodo])ris+=V[vicino];
            }
            cout<<ris<<"\n";
        }else{
            int nodo,newval;
            cin>>nodo>>newval;
            if(adj[nodo].size()<=k){//se il nodo è "piccolo"
                for(int vicino:vicini_grandi[nodo]){ //aggiorno la somma dei vicini grandi
                    S[vicino]+=newval-V[nodo];
                }
            }
            V[nodo]=newval;
        }
    }
    

}