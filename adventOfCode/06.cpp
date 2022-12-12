#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    string s;
    cin>>s;
    for(int i=13;i<s.size();i++){
        set<char>tmp;
        for(int j=i-13;j<=i;j++){
            tmp.insert(s[j]);
        }
        if(tmp.size()==14){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    cout<<"NO\n";
}