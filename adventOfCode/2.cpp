#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("input.txt");
    int score=0;
    string a,b;
    while(cin>>a>>b){
        int t1,t2;
        if(a=="A")t1=0;
        else if(a=="B")t1=1;
        else t1=2;
        if(b=="X")t2=(t1+2)%3,score+=0;
        else if(b=="Y")t2=t1,score+=3;
        else t2=(t1+1)%3,score+=6;
        score+=t2+1;
        //cout<<a<<" "<<b<<" "<<score<<" "<<t1<<" "<<t2<<"\n";
    }
    cout<<score<<"\n";
}