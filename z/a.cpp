#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAXN 4002
struct task{
    int id;
    int sz;
    int datasz;
    vector<int>aff_machine;
};
struct machine{
    int id;
    int power;
};
struct disk{
    int id;
    int speed;
    int capacity;
};
int ntask;
int nmachine;
int ndisk;
vector<vector<int> >data_adj(MAXN),data_inv_adj(MAXN),task_adj(MAXN),task_inv_adj(MAXN);

vector<task>Tasks;
vector<disk>Disks;
vector<machine>Machines;
int main(){
    cin>>ntask;
    for(int i=0;i<ntask;i++){
        task tmp;
        cin>>tmp.id>>tmp.sz>>tmp.datasz;
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int supp;
            cin>>supp;
            tmp.aff_machine.push_back(supp);
        }
        Tasks.push_back(tmp);
    }

    cin>>nmachine;
    for(int i=0;i<nmachine;i++){
        machine tmp;
        cin>>tmp.id>>tmp.power;
        Machines.push_back(tmp);
    }
    cin>>ndisk;
    for(int i=0;i<ndisk;i++){
        disk tmp;
        cin>>tmp.id>>tmp.speed>>tmp.capacity;
        Disks.push_back(tmp);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        data_adj[a].push_back(b);
        data_inv_adj[b].push_back(a);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        task_adj[a].push_back(b);
        task_inv_adj[b].push_back(a);
    }

}