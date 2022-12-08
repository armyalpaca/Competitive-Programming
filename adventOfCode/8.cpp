#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<string>ar;
int gm(int x1,int y1){
    if(x1==0||x1==n-1||y1==0||y1==m-1)return 0;
    int c1=1,c2=1,c3=1,c4=1;
    for(int i=x1+1;i<n&&ar[i][y1]<ar[x1][y1];i++){
        c1++;
        if(i==n-1)c1--;
    }
    for(int i=x1-1;i>=0&&ar[i][y1]<ar[x1][y1];i--){
        c2++;
        if(i==0)c2--;
    }
    for(int i=y1+1;i<m&&ar[x1][i]<ar[x1][y1];i++){
        c3++;
        if(i==m-1)c3--;
    }
    for(int i=y1-1;i>=0&&ar[x1][i]<ar[x1][y1];i--){
        c4++;
        if(i==0)c4--;
    }
    return c1*c2*c3*c4;
}
int main(){
    ifstream cin("input.txt");
    string s;
    while(cin>>s){
        ar.push_back(s);
    }
    int ris=0;
    n=ar.size(),m=ar[0].size(); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ris=max(ris,gm(i,j));
        }
    }
    cout<<ris<<"\n";
}