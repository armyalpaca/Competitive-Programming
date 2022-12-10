#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > mat(100,vector<char>(40,' '));
int main(){
    ifstream cin("input.txt");
    int cnt=0,n,s1=1,s2=0;
    string s;
    while(cin>>s){
        if(cnt%40>=s1-1&&cnt%40<=s1+1){
            mat[cnt/40][cnt%40]='#';
        }else{
            mat[cnt/40][cnt%40]='.';
        }
        if(s=="noop"){
            cnt++;
            if(cnt%40==20){
                s2+=s1*cnt;
            }
        }else{
            if((cnt+1)%40>=s1-1&&(cnt+1)%40<=s1+1){
                mat[(cnt+1)/40][(cnt+1)%40]='#';
            }else{
                mat[(cnt+1)/40][(cnt+1)%40]='.';
            }
            cnt+=2;
            cin>>n;
            s1+=n;
        }
    }

    ofstream cout("output.txt");
    for(int i=0;i<20;i++){
        for(int j=0;j<40;j++){
            cout<<mat[i][j];
        }
        cout<<"\n";
    }
} 