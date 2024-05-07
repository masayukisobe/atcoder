// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,M;
  cin >> N >> M;
  vi s(M),c(M);
  rep(j,M) cin >> s[j] >> c[j];
  rep (i,1000) {
    string t = to_string(i);
    if (t.size()!=N) continue;
    bool ok = true;
    rep(j,M) {
      if (t[s[j]-1]!=char('0'+c[j])) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

