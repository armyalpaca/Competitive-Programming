#include <bits/stdc++.h>
using namespace std;
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

class Dinic {
    public:
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    //numero nodi , sorgente, destinazione
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, cap);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    Dinic d=Dinic(n+1,1,n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        d.add_edge(a,b,1);
    }
    cout<<d.flow()<<"\n";

    vector<bool>vis(n+1,false);
    vis[1]=true;
    queue<int>coda;
    coda.push(1);
    while (!coda.empty()){
        int nodo=coda.front();

        coda.pop();
        for (int id : d.adj[nodo]) {
            if (d.edges[id].flow <=0&&!vis[d.edges[id].u]){
                coda.push(d.edges[id].u);
                vis[d.edges[id].u]=true;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(!vis[i])continue;
        for(int x:d.adj[i]){
            if(!vis[d.edges[x].u]){
                cout<<i<<" "<<d.edges[x].u<<"\n";
            }
        }
    }
    

}