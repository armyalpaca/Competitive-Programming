#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define mod 1000000007
map<string,vector<int> >mappa1;
map<string,vector<int> >mappa2;
vector<string>ar(MAXN);
bool palindroma(string a){
    for(int i=0;i<a.size()/2;i++){
        if(a[i]!=a[a.size()-i-1])return false;
    }
    return true;
}
long long contapre[MAXN][104];
long long contasuff[MAXN][105];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++)cin>>ar[i];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            string s1=ar[i];
            for(int k=0;k<ar[j].size();k++){
                s1+=ar[j][k];
                if(palindroma(s1)){
                    contapre[j][k]++;
                }
            }
            s1="";
            for(int k=ar[j].size()-1;k>=0;k--){
                s1+=ar[j][k];
                if(palindroma(s1+ar[i]))contasuff[j][k]++;
            }
        }
    }
    int palindrome=0;
    for(int i=0;i<N;i++){
        if(palindroma(ar[i]))palindrome++;
    }
    long long ris=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(ar[i].size()>ar[j].size()){
                int len=ar[j].size();
                if(!palindroma(ar[i].substr(0,len)+ar[j]))continue;
                ris+=contasuff[i][ar[j].size()];
            }else if(ar[i].size()<ar[j].size()){
                int len=ar[i].size();
                if(!palindroma(ar[i]+ar[j].substr(ar[j].size()-len,len)))continue;
                ris+=contapre[j][ar[j].size()-len-1];
            }else{
                int len=ar[j].size();
                if(!palindroma(ar[i]+ar[j]))continue;
                ris+=palindrome;
            }
            ris%=mod;
        }
    }
    cout<<ris<<"\n";
}