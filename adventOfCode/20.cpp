#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
    vector<pair<int,int> >ar;
    int n=0;
    int tmp;
    while(cin>>tmp){
        n++;
        tmp*=811589153;
        ar.push_back({tmp,n-1});
        
    }
    vector<pair<int,int> >supp=ar;
    for(int k=0;k<10;k++){
        for(int i=0;i<supp.size();i++){
            int pos=-1;
            for(int j=0;j<n;j++){
                if(ar[j].second==i){
                    pos=j;
                    break;
                }
            }
            int pos_finale=(pos+supp[i].first+(n-1)*10000000000000)%(n-1);
            while(pos<pos_finale){
                swap(ar[pos],ar[pos+1]);
                pos++;
            }
            while(pos>pos_finale){
                swap(ar[pos],ar[pos-1]);
                pos--;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(ar[i].first==0){
            cout<<ar[(i+1000)%n].first+ar[(i+2000)%n].first+ar[(i+3000)%n].first<<"\n";

        }
    }
   
}