

#include <bits/stdc++.h> 
using namespace std;
#pragma once
int block_size;

class moalgorithm{
    vector<int>ar;
    int n;
    moalgorithm(vector<int>a){
        n=a.size();
        ar=a;
    }
    void remove(int idx);  // TODO: remove value at idx from data structure
    void add(int idx);     // TODO: add value at idx from data structure
    int get_answer();  // TODO: extract the current answer of the data structure
    struct Query {
        int l, r, idx;
        bool operator<(Query other) const
        {
            return make_pair(l / block_size, r) <
                make_pair(other.l / block_size, other.r);
        }
    };

    vector<int> mo_s_algorithm(vector<Query> queries) {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());

        // TODO: initialize data structure

        int cur_l = 0;
        int cur_r = -1;
        // invariant: data structure will always reflect the range [cur_l, cur_r]
        for (Query q : queries) {
            while (cur_l > q.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < q.r) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < q.l) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > q.r) {
                remove(cur_r);
                cur_r--;
            }
            answers[q.idx] = get_answer();
        }
        return answers;
    }
};
