#include <bits/stdc++.h>

using namespace std;
map<string,bool>mappa;
bool test(string qry);
int ok=170;
bool ask(string s){
    if(mappa.find(s)==mappa.end())return mappa[s]=test(s);
    return mappa[s];

}
string sol1(int N){
    string a=string(ok,'0');
    int tmp=0;
    int last=ok;
    while(a.size()<N){
        if(ask(a+"1")){
            a+="1";
            last=a.size();
        }else{
            a+="0";
        }
        tmp++;
        if(tmp*tmp==N){
            if(!ask(a)){
                break;
            }else{
                last=a.size();
                tmp=0;
            }
        }
    }
    if(a.size()==N&&ask(a))return a;
    string ris=a.substr(0,last);
    a=a.substr(last);
    int low=0,high=a.size()-1;
    while(low<high){
        int mid=(low+high+1)/2;
        if(ask(ris+a.substr(0,mid))){
            low=mid;
        }else{
            high=mid-1;
        }
    }
    ris=ris+a.substr(0,low);
    while(ris.size()<N){
        if(ask("1"+ris)){
            ris="1"+ris;
        }else{
            ris="0"+ris;
        }
    }
    return ris;
}
string analizza(int N){
    mappa.clear();
    if(ask(string(ok,'0'))){
        return sol1(N);
    }
    int low=0,high=ok-1;
    while(low<high){
        int mid=(low+high+1)/2;
        if(ask(string(mid,'0'))){
            low=mid;
        }else{
            high=mid-1;
        }
    }

    string a=string(low,'0');
    string b=a;
    while(a.size()-b.size()<=low&&a.size()<N){
        if(ask(a+"1")){
            a=b=a+"1";
        }else{
            a+="0";
        }
    }
    high=low;
    low=0;
    while(ask(b+"0")){
        b+="0";
    }
    /*while(low<high){
        int mid=(low+high+1)/2;
        if(ask(b+string(mid,'0'))){
            low=mid;
        }else{
            high=mid-1;
        }
    }
    b=b+string(low,'0');*/
    while (b.size()<N)
    {
        if(ask("0"+b)){
            b="0"+b;
        }else{
            b="1"+b;
        }
    }
    return b;
}