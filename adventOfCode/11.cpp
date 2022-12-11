#include <bits/stdc++.h>
using namespace std;
vector<queue<long long> >items(8);
array<int,2>OP[8];
array<int,3>manda[8];
long long mod=9699690;
int conta[8];
int main(){
    ifstream cin("input.txt");
    for(int i=0;i<8;i++){
        int tmp;
        cin>>tmp;
        for(int j=0;j<tmp;j++){
            int tmp2;
            cin>>tmp2;
            items[i].push(tmp2);
        }
        cin>>OP[i][0];
        if(OP[i][0]!=1)cin>>OP[i][1];
        cin>>manda[i][0]>>manda[i][1]>>manda[i][2];

    }
    cout<<"OK"<<endl;
    int turni=10000;
    while(turni--){
        for(int i=0;i<8;i++){
            while(!items[i].empty()){
                long long item=items[i].front();
                items[i].pop();
                conta[i]++;
                if(OP[i][0]==0)item*=OP[i][1];
                else if(OP[i][0]==1)item*=item;
                else item+=OP[i][1];
                item%=mod;
                if(item%manda[i][0]==0){
                    items[manda[i][1]].push(item);
                }else{
                    items[manda[i][2]].push(item);
                }

            }
        }
    }
    sort(conta,conta+8);
    cout<<(long long)conta[7]*conta[6]<<"\n";
}