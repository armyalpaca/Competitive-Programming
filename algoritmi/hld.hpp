#include <bits/stdc++.h>
using namespace std;
#include "segmentTree.hpp"
#pragma once
class HLD{
    int n;
    vector<vector<int> >adj;
    vector<long long>val;
    vector<int>heavy,depth,head,pos,parent;
    SegmentTreeSum st;
    int cur_pos=0;
    int dfs(int nodo) {
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[nodo]) {
            if (c != parent[nodo]) {
                parent[c] = nodo, depth[c] = depth[nodo] + 1;
                int c_size = dfs(c);
                size += c_size;
                if (c_size > max_c_size)
                    max_c_size = c_size, heavy[nodo] = c;
            }
        }
        return size;
    }
    void decompose(int v, int h) {
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h);
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c);
        }
    }
    public:
    HLD(vector<vector<int> >adj_,vector<int>v_){
        adj=adj_;
        val=v_;
        n=adj.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        st=SegmentTreeSum(val);
        dfs(0);
        decompose(0,0);
        
        for(int i=0;i<n;i++){
            st.modify(pos[i],pos[i],val[i]);
        }
    }
    long long query(int a, int b) {
        long long res = 0;
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            res+= st.query(pos[head[b]], pos[b]);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        res+= st.query(pos[a], pos[b]);
        return res;
    }
    void modify(int a,int b,long long val){
        for (; head[a] != head[b]; b = parent[head[b]]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            st.modify(pos[head[b]], pos[b],val);
        }
        if (depth[a] > depth[b])
            swap(a, b);
        st.modify(pos[a],pos[b],val);
    }
};