#include <bits/stdc++.h>
using namespace std;
bool check(string a,char c){
    for(char x:a)if(x!=c)return false;
    return true;
}
int f(string a,string b){
    if(check(a,'A')&&check(b,'B'))return 0;
    if(check(a,'A')&&check(b,'B'))return 0;
    int pos=-1;

    for(int i=0;i<a.size();i++){
        if(a[i]=='B'&&i==(int)a.size()-1){
            pos=i;
            break;
        }
        if(a[i]=='B'&&a[i+1]=='A'){
            pos=i;
            break;
        }
    }
    int pos2=-1;
    for(int i=0;i<b.size();i++){
        if(b[i]=='A')pos2=i;
    }
    string a2=b.substr(0,pos2+1)+a.substr(pos+1);
    string b2=a.substr(0,pos+1)+b.substr(pos2+1);
    int tmp;
    //cin>>tmp;

    //cout<<a2<<"\n"<<b2<<"\n---------------\n";
    return 1+f(a2,b2);
}
int f2(string a,string b){
    if(check(a,'B')&&check(b,'A'))return 0;
    if(check(a,'A')&&check(b,'B'))return 0;
    int pos=-1;

    for(int i=0;i<a.size();i++){
        if(a[i]=='A'&&i==(int)a.size()-1){
            pos=i;
            break;
        }
        if(a[i]=='A'&&a[i+1]=='B'){
            pos=i;
            break;
        }
    }
    int pos2=-1;
    for(int i=0;i<b.size();i++){
        if(b[i]=='B')pos2=i;
    }
    string a2=b.substr(0,pos2+1)+a.substr(pos+1);
    string b2=a.substr(0,pos+1)+b.substr(pos2+1);
    int tmp;
    //cin>>tmp;

    //cout<<a2<<"\n"<<b2<<"\n---------------\n";
    return 1+f2(a2,b2);
}
int main(){
    string s1,s2;
    while(true){
        int tmp;
        cin>>tmp;
        string s1,s2;
        int n1=rand()%tmp+1,n2=rand()%tmp+1;
        s1+=rand()%2+'A';
        s2+=rand()%2+'A';
        for(int i=1;i<n1;i++){
            if(s1[i-1]=='A')s1+='B';
            else s1+='A';
        }
        
        for(int i=1;i<n2;i++){
            if(s2[i-1]=='A')s2+='B';
            else s2+='A';
        }
        cout<<n1<<" "<<s1<<"\n"<<n2<<" "<<s2<<"\n-------------------\n";
        cout<<f(s1,s2)<<" "<<f(s2,s1)<<" "<<f2(s1,s2)<<" "<<f2(s2,s1)<<"\n";

    }

}