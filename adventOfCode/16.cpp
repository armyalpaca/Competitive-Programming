#include <bits/stdc++.h>
using namespace std;

map<string,vector<string> >adj;
map<string,map<string,int> >dist;
map<string,int>flow;
vector<pair<int,string> >ok;
map<pair<long long,pair<pair<int,string>,pair<int,string> > >,int>dp;
map<string,int>pos;
int risfinale=0;
int sommacap=0;
int ric(int tempo1,string nodo1,int tempo2,string nodo2,int supp,long long visi){
    if(dp[{visi,{{tempo1,nodo1},{tempo2,nodo2}}}]!=0)return dp[{visi,{{tempo1,nodo1},{tempo2,nodo2}}}];
    if(sommacap*max(tempo1-2,tempo2-2)+supp<=risfinale)return 0;
    vector<int>cap;
    for(auto y:ok){
        if(flow[y.second]>0){
            cap.push_back(flow[y.second]);
        }
    }

    sort(cap.rbegin(),cap.rend());
    int t1=tempo1,t2=tempo2,supp2=0;
    for(int x:cap){
        if(max(t1,t2)<=1)break;
        if(t1>t2){
            supp2+=(t1-2)*x;
            t1-=2;
        }else{
            supp2+=(t2-2)*x;
            t2-=2;
        }
    }

    if(supp+supp2<=risfinale)return 0;
    //cout<<tempo1<<" "<<nodo1<<" "<<tempo2<<" "<<nodo2<<"\n";
    risfinale=max(risfinale,supp);
    int ris=0;
    if(tempo1>2){
        for(auto y:ok){
            string x=y.second;
            if(flow[x]>0&&dist[nodo1][x]+1<tempo1){
                int tmp=flow[x];
                sommacap-=tmp;
                flow[x]=0;
                ris=max(ris,ric(tempo1-dist[nodo1][x]-1,x,tempo2,nodo2,supp+tmp*(tempo1-dist[nodo1][x]-1),visi|(long long)1<<pos[x])+tmp*(tempo1-dist[nodo1][x]-1));
                sommacap+=tmp;
                flow[x]=tmp;
            }
        }
        
    }
    if(tempo2>1){
        for(auto y:ok){
            string x=y.second;
            if(flow[x]>0&&dist[nodo2][x]+1<tempo2){
                int tmp=flow[x];
                sommacap-=tmp;
                flow[x]=0;
                ris=max(ris,ric(tempo1,nodo1,tempo2-dist[nodo2][x]-1,x,supp+tmp*(tempo1-dist[nodo1][x]-1),visi|(long long)1<<pos[x])+tmp*(tempo2-dist[nodo2][x]-1));
                sommacap+=tmp;
                flow[x]=tmp;
            }
        }
    }
    
    return dp[{visi,{{tempo1,nodo1},{tempo2,nodo2}}}]=ris;
}
int main(){
    char s[200];
    ifstream cin("input.txt");
    while(cin.getline(s,199)){
        string nodo="";
        nodo+=s[6];
        nodo+=s[7];
        int capienza=0;
        for(int i=0;i<199;i++){
            if(s[i]=='='){
                int j=i+1;
                while(s[j]>='0'&&s[j]<='9'){
                    capienza*=10;
                    capienza+=s[j]-'0';
                    j++;
                }
                break;
            }
        }
  
        flow[nodo]=capienza;
        sommacap+=capienza;
        if(capienza>0)ok.push_back({capienza,nodo});
        for(int i=100;i>0;i--){
            if(s[i]=='s'){
                int j=i+1;
                string vicino="";
                while(s[j]!='\0'){
                    if(s[j]==','){
                        adj[nodo].push_back(vicino);
                        vicino="";
                    }
                    if(s[j]>='A'&&s[j]<='Z'){
                        vicino+=s[j];
                    }
                    j++;
                }
                adj[nodo].push_back(vicino);
                break;
            }
        }
    }
    sort(ok.rbegin(),ok.rend());
    int p=0;
    for(auto x:ok){
        pos[x.second]=p++;
    }
    for(auto nodi:adj){
    
        queue<string>coda;
        map<string,bool>vis;
        coda.push(nodi.first);
        vis[nodi.first]=1;
        while(!coda.empty()){
            string nodo=coda.front();
            coda.pop();
            for(auto x:adj[nodo]){
                if(!vis[x]){
                    vis[x]=1;
                    dist[nodi.first][x]=dist[nodi.first][nodo]+1;
                    coda.push(x);
                }
            }
        }
    }
    /*for(auto start:dist){
        cout<<start.first<<" :";
        for(auto x:start.second){
            cout<<x.first<<" "<<x.second<<" | ";
        }
        cout<<"\n";
    }*/
    cout<<ok.size()<<"\n";
    cout<<ric(26,"AA",26,"AA",0,0)<<"\n";
}