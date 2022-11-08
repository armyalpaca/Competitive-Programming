#include <bits/stdc++.h>
#include "fenwick.hpp"
#include "segmentTree.hpp"
using namespace std;
int main(){
    FenwickTree a=FenwickTree(10);
    a.changeValue(1,5);
    cout<<a.getSum(1,10)<<"\n";
    SegmentTreeSum b=SegmentTreeSum(10);
    b.modify(1,2,10);
    cout<<b.query(0,2)<<"\n";
}