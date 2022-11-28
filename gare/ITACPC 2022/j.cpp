#include <bits/stdc++.h>
using namespace std;
int dist(array<int,2>a,array<int,2>b){
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
}
int main(){
    int N,M;
    cin>>M;
    vector<int>boot(M);
    for(int i=0;i<M;i++){
        cin>>boot[i];
    }
    sort(boot.begin(),boot.end()); //ordino gli stand
    int X,Y;//pos samu;
    cin>>X>>Y;
    cin>>N; 
    vector<array<int,2> >C(N); //X, Y dei contestants
    for(int i=0;i<N;i++){
        cin>>C[i][0]>>C[i][1];
    }
    vector<vector<int> >tempi(M);
    for(int i=0;i<N;i++){
        if(boot[0]>=C[i][1]){
            tempi[0].push_back(dist({0,boot[0]},C[i]));
            continue;
        }
        int low=0,high=M-1;//primo minore <=
        while(low<high){//trovo il primo stand con boot[low]<=C[i][1]
            int mid=(low+high+1)/2;
            if(boot[mid]>C[i][1])high=mid-1;
            else low=mid;
        }
        
        if(low==M-1||dist({0,boot[low]},C[i])<=dist({0,boot[low+1]},C[i])){ //se sono alla fine oppure 
            tempi[low].push_back(dist({0,boot[low]},C[i]));
        }else{
            tempi[low+1].push_back(dist({0,boot[low+1]},C[i]));
        }
    }
    for(int i=0;i<M;i++){
        sort(tempi[i].begin(),tempi[i].end());
    }
    
    int ris=1e9;
    for(int i=0;i<M;i++){
        int tmp=dist({X,Y},{0,boot[i]});
        if(tempi[i].size()==0||tempi[i][0]>tmp){
            ris=0;
            continue;
        }
        int low=0,high=tempi[i].size()-1;
        while(low<high){
            int mid=(low+high+1)/2;
            if(tempi[i][mid]<=tmp){
                low=mid;
            }else{
                high=mid-1;
            }
        }
        ris=min(ris,low+1);
    }
    cout<<ris<<"\n";


}