#include <bits/stdc++.h>
using namespace std;
int dp[100004][10][10];
string s;
int f(int pos,int i,int j){
    if(pos>=(int)s.size()){
        return 0;
    }
    if(dp[pos][i][j]!=-1)return dp[pos][i][j];
    if(i==j){
        int ris=1e9;
        for(int i1=0;i1<10;i1++){
            for(int j1=i1+1;j1<10;j1++){
                int tmp=f(pos+1,i1,j1);
                if((int)s[pos]-'0'==i1){
                    tmp+=abs(j1+'0'-(pos==0?'0':s[pos-1]));
                }else if((int)s[pos]-'0'==j1){
                    tmp+=abs(i1+'0'-(pos==0?'0':s[pos-1]));
                }else{
                    tmp+=abs(s[pos]-(pos==0?'0':s[pos-1]));
                }
                ris=min(ris,tmp);
            }
        }

        int supp=f(pos+1,i,j)+abs(s[pos]-(pos==0?'0':s[pos-1]));
        ris=min(ris,supp);
        
        return dp[pos][i][j]=ris;
    }else{
        int a=s[pos-1]-'0',b=s[pos]-'0';
        if(a==i){
            a=j;
        }else if(a==j){
            a=i;
        }
        if(b==i){
            b=j;
        }else if(b==j){
            b=i;
        }
        return dp[pos][i][j]=abs(a-b)+f(pos+1,i,j);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        int n=s.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        cout<<f(0,0,0)<<"\n";
    }

}