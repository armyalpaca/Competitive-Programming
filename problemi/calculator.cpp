#include <bits/stdc++.h>
using namespace std;
map<int,array<int,3> >from;
string opp[]={"+","-","/","%","&","^","|",">>","*","<<"};
string f(int n){
    if(n==1)return "1";
    return "("+f(from[n][0])+")"+opp[from[n][2]]+"("+f(from[n][1])+")";
}
int main(){
    set<int>fatto;
    fatto.insert(1);
    vector<vector<int> >ar(100);
    
    ar[0].push_back(1);
    int conta=1;
    for(int costo=1;costo<100;costo++){
        for(int i=0;i<costo;i++){
            int j=costo-1-i;
            
            for(int a:ar[i]){
                for(int b:ar[j]){
                    if(a==0||b==0)continue;
                    vector<int>supp={a+b,a-b,a/b,a%b,a&b,a^b,a|b,a>>b};
                    if(a*b<100000)supp.push_back(a*b);
                    else supp.push_back(-1);
                    if(b<15){
                        int tmp=a;
                        bool ok=true;
                        for(int p=0;p<b;p++){
                            tmp*=2;
                            if(tmp>100000){
                                ok=false;
                                break;
                            }
                        }
                        if(ok)supp.push_back(a<<b);
                        else supp.push_back(-1);
                    }else{
                        supp.push_back(-1);
                    }
                    for(int xx=0;xx<supp.size();xx++){
                        int x=supp[xx];
                        if(x>=0&&x<100000&&!fatto.count(x)){
                            fatto.insert(x);
                            if(x<=3000)conta++;
                            ar[costo].push_back(x);
                            from[x]={a,b,xx};
                        }
                    }
                }
            }
            if(conta>=3001){
                break;
            }
        }
        if(conta>=3001)break;
    }
    int m;
    cin>>m;
    cout<<f(m)<<"\n";

    
}