#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int somma=0;
    string s1,s2,s3;
    while(cin>>s1>>s2>>s3){
        set<char>ok1,ok2;
        for(int i=0;i<s1.size();i++){
            ok1.insert(s1[i]);
        }
        for(int i=0;i<s2.size();i++)ok2.insert(s2[i]);
        for(int i=0;i<s3.size();i++){
            if(ok1.count(s3[i])&&ok2.count(s3[i])){
                if(s3[i]<='Z'){
                    somma+=s3[i]-'A'+27;
                }else{
                    somma+=s3[i]-'a'+1;
                }
                break;
            }
        }
    }
    cout<<somma<<"\n";
}