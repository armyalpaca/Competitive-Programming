#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        long long n,r,t;
        cin>>n>>r>>t;
        long long somma=0;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            somma+=tmp;
        }
        if((double)somma/n-r>=t){
            cout<<"Cheater\n";
        }else{
            cout<<"Innocent\n";
        }
    }
    
}   