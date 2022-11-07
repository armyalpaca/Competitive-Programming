#include <bits/stdc++.h>
#include "fenwick.hpp"
using namespace std;
int main(){
    FenwickTree a=FenwickTree(10);
    a.changeValue(1,5);
    cout<<a.getSum(1,10)<<"\n";
}