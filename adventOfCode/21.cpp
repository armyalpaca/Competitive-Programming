#include <bits/stdc++.h>
using namespace std;
char s[40];
map<string,pair<string,string> >m1;
map<string,int>m2;
map<string,char>m3;
long long dfs(string nodo,long long val){
    if(m2[nodo]>-1e9)return m2[nodo];
    if(nodo=="humn"){
        return val;
    }
    //cout<<nodo<<"\n";
    long long a=dfs(m1[nodo].first,val),b=dfs(m1[nodo].second,val);
    if(m3[nodo]=='+')return a+b;
    if(m3[nodo]=='-')return a-b;
    if(m3[nodo]=='*')return a*b;
    if(m3[nodo]=='/')return a/b;
}
int main(){
    ifstream cin("input.txt");
    while(cin.getline(s,39)){
        string a="",b="",c="";
        if(s[6]>='0'&&s[6]<='9'){
            for(int i=0;i<4;i++){
                a+=s[i];
            }
            int tmp=0;
            for(int i=6;s[i]>='0'&&s[i]<='9';i++){
                tmp*=10;
                tmp+=s[i]-'0';
            }
            m2[a]=tmp;
        }else{
            for(int i=0;i<4;i++){
                a+=s[i];
                b+=s[6+i];
                c+=s[13+i];
            }
            m1[a]={b,c};
            m2[a]=-1e9;
            m3[a]=s[11];
        }
        
    }
   
}