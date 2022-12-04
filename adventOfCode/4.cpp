#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int ris=0;
    int a,b,c,d;
    char tmp;
    while(cin>>a>>tmp>>b>>tmp>>c>>tmp>>d){
        if((a<=c&&b>=c)||(a<=d&&b>=d)){
            ris++;
            continue;
        }
        if((c<=a&&d>=a)||(c<=b&&d>=b)){
            ris++;
        }
    }
    cout<<ris<<"\n";
}