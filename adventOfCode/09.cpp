#include <bits/stdc++.h>
using namespace std;
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
int xi[10],yi[10];
int main(){
    ifstream cin("input.txt");
    set<array<int,2> >vis;
    string m;
    int a;
    vis.insert({0,0});
    int ind;
    while(cin>>m>>a){
        if(m=="R")ind=0;
        if(m=="L")ind=1;
        if(m=="D")ind=2;
        if(m=="U")ind=3;

        while(a--){
            xi[0]+=mx[ind];
            yi[0]+=my[ind];
            for(int i=1;i<10;i++){
                int x1=xi[i-1],y1=yi[i-1],x2=xi[i],y2=yi[i];              
                if(max(abs(x1-x2),abs(y1-y2))<=1){
                    //sto fermo
                }else if(x1==x2){
                    if(y1<y2)y2--;
                    else y2++;
                }else if(y1==y2){
                    if(x1<x2)x2--;
                    else x2++;
                }else{
                    if(x2<x1&&y2<y1)x2++,y2++;
                    else if(x2<x1&&y2>y1)x2++,y2--;
                    else if(x2>x1&&y2<y1)x2--,y2++;
                    else if(x2>x1&&y2>y1)x2--,y2--;
                }
                xi[i]=x2;
                yi[i]=y2;
            }
            vis.insert({xi[9],yi[9]});

        }


    }
    cout<<vis.size()<<"\n";
} 