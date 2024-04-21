// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#include <atcoder/all>
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,M;
  cin >> N >> M;
  scc_graph g(N);
  for (int i=0; i<M; i++) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    g.add_edge(a,b);
    g.add_edge(b,a);
  }
  ll ans = -M;
  auto groups = g.scc();
  for (auto group: groups) {
    ll n = group.size();
    // debug(n);
    if (n>=2) {
      ans += n*(n-1)/2;
    }
  }
  cout << ans << endl;
  return 0;
}

