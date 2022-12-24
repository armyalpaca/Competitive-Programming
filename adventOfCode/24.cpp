#include <bits/stdc++.h>
using namespace std;
int mx[]={1,-1,0,0,0};
int my[]={0,0,1,-1,0};
int dist[3][1500][30][150];
bool vis[3][1500][30][150];
vector<char>mat[1500][30][150];
string start[30];
int prev(int i,int k){
    if(i==1){
        return k-2;
    }
    return i-1;
}
int nex(int i,int k){
    if(i==k-2)return 1;
    return i+1;
}
int main(){
    ifstream cin("input.txt");
    string supp;
    int n=0,m;
    while(cin>>start[n++]){
    }
    n--;
    cout<<"OK"<<endl;
    cout<<n<<endl;
    m=start[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout<<start[i][j];
            if(start[i][j]!='#'&&start[i][j]!='.'){
                mat[0][i][j].push_back(start[i][j]);
            }
        }
    }
    
    array<int,2>s,e;
    for(int i=0;i<m;i++){
        if(start[0][i]=='.'){
            s={0,i};
        }
        if(start[n-1][i]=='.')e={n-1,i};
    }
   
    for(int t=1;t<1500;t++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(char c:mat[t-1][i][j]){
                    if(c=='<'){
                        mat[t][i][prev(j,m)].push_back(c);
                    }else if(c=='>'){
                        mat[t][i][nex(j,m)].push_back(c);
                    }else if(c=='v'){
                        mat[t][nex(i,n)][j].push_back(c);
                    }else if(c=='^'){
                        mat[t][prev(i,n)][j].push_back(c);
                    }
                }
            }
        }
        
    }
    queue<array<int,4> >coda;
    coda.push({0,0,s[0],s[1]});
    dist[0][0][s[0]][s[1]]=0;

    while(!coda.empty()){
        int ok=coda.front()[0],t=coda.front()[1],x=coda.front()[2],y=coda.front()[3];
        coda.pop();
        if(t>=1499)continue;
        if(x==e[0]&&y==e[1]){
            //cout<<ok<<" "<<t<<"\n";
            if(ok==2){
                cout<<t<<"\n";
                return 0;
            }
            if(ok==0){
                vis[1][t][e[0]][e[1]]=1;
                coda.push({1,t,e[0],e[1]});
            }
        }
        if(x==s[0]&&y==s[1]){
            if(ok==1){
                //cout<<"aa "<<t<<"\n";
                vis[1][t][x][y]=1;
                coda.push({2,t,x,y});
            }
        }
        for(int i=0;i<5;i++){
            int px=x+mx[i],py=y+my[i];
        
            if(px<0||px>=n||py<0||py>=m||vis[ok][t+1][px][py]||start[px][py]=='#'||mat[t+1][px][py].size()>0){
                continue;
            }
            vis[ok][t+1][px][py]=1;
            dist[ok][t+1][px][py]=t+1;
            coda.push({ok,t+1,px,py});
        }
    }


}