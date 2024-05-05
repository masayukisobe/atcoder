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
  vector<ii> e(M);
  for (int i=0; i<M; i++) {
    int a,b; cin >> a >> b; a--,b--;
    e[i] = ii(a,b);
  }
  int ans = 0;
  for (int i=0; i<M; i++) {
    dsu d(N);
    for (int j=0; j<M; j++) {
      if (i==j) continue;
      auto [a,b] = e[j];
      d.merge(a,b);
    }
    auto [x,y] = e[i];
    if (!d.same(x,y)) ans++;
  }
  cout << ans << endl;
  return 0;
}

