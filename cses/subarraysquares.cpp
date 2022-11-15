#include <bits/stdc++.h>
using namespace std;
#define MAXN 3005

int m, n;
vector<long long> dp_before(MAXN), dp_cur(MAXN);
vector<long long>pref(MAXN);
long long C(int i, int j){
    return (pref[j]-(i==0?0:pref[i-1]))*(pref[j]-(i==0?0:pref[i-1]));
}

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};

    for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

long long solve() {
    for (int i = 0; i < n; i++)
        dp_before[i] = C(0, i);

    for (int i = 1; i < m; i++) {
        compute(0, n - 1, 0, n - 1);
        dp_before = dp_cur;
    }

    return dp_before[n - 1];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        pref[i]=tmp;
        if(i!=0)pref[i]+=pref[i-1];
    }
    cout<<solve()<<"\n";
}