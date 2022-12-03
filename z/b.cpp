#include <bits/stdc++.h>
using namespace std;
int f(int x){
    if(x%2==0)return 0;
    return 1+f((x-1)/2);
}
int g(int x){
    if(x>250||x<=0)return 0;
    return max(f(x),g(x/2));
}
int main(){ 
    for(int i=1;i<250;i++){
        if(g(i)==1)cout<<i<<"\n";
    }
}
