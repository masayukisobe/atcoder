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

  dsu d(N);
  
  vector<vector<int>> e(M);
  vector<ii> f(M);
  for (int i=0; i<M; i++) {
    int k, c; cin >> k >> c;
    e[i].reserve(k);
    for (int j=0; j<k; j++) {
      int a; cin >> a; a--;
      e[i].push_back(a);
    }
    f[i] = ii(c,i);
  }
  sort(f.begin(),f.end());
  ll ans = 0;
  for (auto [c,i] : f) {
    vector<int> &a = e[i];
    for (int j=1; j<a.size(); j++) {
      int p = a[j-1];
      int q = a[j];
      if (!d.same(p,q)) {
        //cout << p+1 << " " << q+1 << " " << c << endl;
        ans += c;
        d.merge(p,q);
      }
    }
  }
  if (d.size(0)==N) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}

