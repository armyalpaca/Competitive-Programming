#include <bits/stdc++.h>
using namespace std;
bool mat[1000][1000];
char s[1000];
int main(){
    ifstream cin("input.txt");
    int altezza=0;
    while(cin.getline(s,900)){
        vector<array<int,2> >supp;
        int x1=0,y1=0,x2,y2;
        bool secondo=false;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]>='0'&&s[i]<='9'){
                if(secondo){
                    y1*=10;
                    y1+=s[i]-'0';
                }else{
                    x1*=10;
                    x1+=s[i]-'0';
                }
            }
            if(s[i]==','){
                secondo=true;
            }
            if(s[i]=='-'){
                supp.push_back({x1,y1});
                x1=0,y1=0;
                secondo=false;
            }
        }
        supp.push_back({x1,y1});
        altezza=max(altezza,supp[0][1]);
        for(int i=1;i<supp.size();i++){
            x1=supp[i-1][0],y1=supp[i-1][1],x2=supp[i][0],y2=supp[i][1];
            altezza=max(altezza,supp[i][1]);
            while(x1!=x2){
                mat[x1][y1]=1;
                if(x1<x2)x1++;
                else x1--;
            }
            while(y1!=y2){
                mat[x1][y1]=1;
                if(y1<y2)y1++;
                else y1--;
            }
            mat[x2][y2]=1;
        }
    }
    altezza+=2;
    for(int i=0;i<1000;i++){
        mat[i][altezza]=1;
    }
    int conta=0;
    while(true){
        int px=500,py=0;
        if(mat[500][0])break;
        bool fine=false;
        while(true){
            bool ok=false;
            if(!mat[px][py+1]){
                ok=true;
                py++;
            }else if(px==0||!mat[px-1][py+1]){
                ok=true;
                px--;
                py++;
            }else if(px==999||!mat[px+1][py+1]){
                ok=true;
                px++;
                py++;
            }
            if(px<0||px>999||py>600){
                fine=true;
                break;
            }
            //cout<<px<<" "<<py<<"\n";
            if(!ok){
                mat[px][py]=1;
                conta++;
                break;
            }
            
        }
        if(fine)break;
    }
    cout<<conta<<"\n";
}