// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

#include <atcoder/all>
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const ll big = (1LL<<31);
  
  int N,K;
  cin >> N >> K;
  
  mcf_graph<int,ll> graph(2+2*N);
  const int s=2*N;
  const int g=2*N+1;
  for (int i=0; i<N; i++) {
    graph.add_edge(s,i,K,0);
    graph.add_edge(i+N,g,K,0);
  }
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      ll a;
      cin >> a;
      graph.add_edge(i,j+N,1,big-a);
    }
  }
  graph.add_edge(s,g,N*K,big);
  
  graph.flow(s,g,N*K);
  ll ans = 0;
  vector<vector<char>> res(N,vector<char>(N,'.'));
  for (auto& e : graph.edges()) {
    if (e.from<2*N && e.to<2*N && e.flow>0) {
      ans += big-e.cost;
      int i = e.from;
      int j = e.to-N;
      res[i][j]='X';
    }
  }
  
  cout << ans << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << res[i][j];
    }
    cout << endl;
  }
  return 0;
}

