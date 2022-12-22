#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
    ifstream cin("input.txt");
    int ind=1;
    int ris=0;
    while(cin>>s1>>s2){
        vector<int>ar1;
        int tmp=-1e9;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==']'||s1[i]==','){
                if(tmp!=-1e9)ar1.push_back(tmp);
                if(s1[i]==']')ar1.push_back(-1e5);
                tmp=-1e9; 

            }else if(s1[i]>='0'&&s1[i]<='9'){
                if(tmp==-1e9)tmp=s1[i]-'0';
                else{
                    tmp*=10;
                    tmp+=s1[i]-'0';
                }
            }else if(s1[i]=='['){
                ar1.push_back(1e5);
            }
        }
        if(tmp!=-1e9)ar1.push_back(tmp);
        vector<int>ar2;
        tmp=-1e9;
        for(int i=0;i<s2.size();i++){
            if(s2[i]==']'||s2[i]==','){
                if(tmp!=-1e9)ar2.push_back(tmp);
                if(s2[i]==']')ar2.push_back(-1e5);
                tmp=-1e9; 
            }else if(s2[i]>='0'&&s2[i]<='9'){
                if(tmp==-1e9)tmp=s2[i]-'0';
                else{
                    tmp*=10;
                    tmp+=s2[i]-'0';
                }
            }else if(s2[i]=='['){
                ar2.push_back(1e5);
            }
        }
        if(tmp!=-1e9)ar2.push_back(tmp);
        ar2.push_back(-1e5);
        int a=0,b=0;
        int ok=0;
        while(true){
            if(a==ar1.size()){
                ok=1;
                break;
            }
            if(b==ar2.size()){
                ok=2;
                break;
            }
            if(abs(ar1[a])!=1e5&&abs(ar2[b])!=1e5){
                if(ar1[a]>ar2[b]){
                    ok=2;
                    break;
                }else if(ar1[a]<ar2[b]){
                    ok=1;
                    break;
                }
                a++,b++;
            }else if(ar1[a]==1e5&&ar2[b]==1e5){
                a++,b++;
            }else if(ar1[a]==-1e5&&ar2[b]==-1e5){
                a++,b++;
            }else if(ar1[a]==-1e5){
                ok=1;
                break;
            }else if(ar2[b]==-1e5){
                ok=2;
                break;
            }else if(ar1[a]==1e5){
                a++;
            }else if(ar2[b]==1e5){
                b++;
            }
        }
       if(ok==1)ris+=ind;
        ind++;
        for(int x:ar1)cout<<x<<" ";
        cout<<"\n";
        for(int x:ar2)cout<<x<<" ";
        cout<<"\n\n";
    }
    cout<<ris<<"\n";


}