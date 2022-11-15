#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int taglia(int N, vector<int> B){
    vector<ll>pre(N+1,0);
    for(int i=1;i<=N;i++)pre[i]=pre[i-1]+B[i-1];
    vector<ll>div;
    for(ll i=2;i*i<=N;i++){
        if(N%i==0){
            div.push_back(i);
            if(i*i!=N)div.push_back(N/i);
        }
    }
    
}

int main() {
  // Uncomment the following lines if you want to read or write from files
  // ifstream cin("input.txt");
  // ofstream cout("output.txt");
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> B[i];

  cout << taglia(N, B) << endl;

  return 0;
}