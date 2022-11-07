#include <bits/stdc++.h>
using namespace std;
#pragma once

class SegmentTreeSum
{
    typedef long long ll;
    int n,h;
    vector<ll>st;
    vector<ll>d;
    void build(vector<ll>&ar){
        h = sizeof(int) * 8 - __builtin_clz(n);
        st.resize(2*n,0);
        d.resize(n,0);
        for(int i=n;i<2*n;i++){
            st[i]=ar[i-n];
        }
        for (int i = n - 1; i > 0; --i) st[i] = st[i<<1] + st[i<<1|1];
    }
    void calc(int p, int k) {
        if (d[p] == 0) st[p] = st[p<<1] + st[p<<1|1];
        else st[p] = d[p] * k;
    }
    void apply(int p, int value, int k) {
        st[p] = value * k;
        if (p < n) d[p] = value;
    }
    void build(int l, int r) {
        int k = 2;
        for (l += n, r += n-1; l > 1; k <<= 1) {
            l >>= 1, r >>= 1;
            for (int i = r; i >= l; --i) calc(i, k);
        }
    }
    void apply(int p, int value) {
        st[p] += value;
        if (p < n) d[p] += value;
    }
    void push(int l, int r) {
        int s = h, k = 1 << (h-1);
        for (l += n, r += n-1; s > 0; --s, k >>= 1)
            for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
            apply(i<<1, d[i], k);
            apply(i<<1|1, d[i], k);
            d[i] = 0;
        }
    }
    public:
    SegmentTreeSum(int n){
        h = sizeof(int) * 8 - __builtin_clz(n);
        this->n=n;
        d.resize(n,0);
        st.resize(2*n,0);
    }
    SegmentTreeSum(vector<ll>ar){
        this->n=ar.size();
        build(ar);
    }
    void modify(int l, int r, int value) {
        r++;
        if (value == 0) return;
        push(l, l + 1);
        push(r - 1, r);
        bool cl = false, cr = false;
        int k = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
            if (cl) calc(l - 1, k);
            if (cr) calc(r, k);
            if (l&1) apply(l++, value, k), cl = true;
            if (r&1) apply(--r, value, k), cr = true;
        }
        for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
            if (cl) calc(l, k);
            if (cr && (!cl || l != r)) calc(r, k);
        }
    }
    long long query(int l, int r) {
        r++;
        push(l, l + 1);
        push(r - 1, r);
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += st[l++];
            if (r&1) res += st[--r];
        }
        return res;
    }

};