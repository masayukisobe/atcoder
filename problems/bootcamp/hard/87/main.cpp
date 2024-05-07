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

#include <atcoder/all>
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N, M, K;
  cin >> N >> M >> K;

  vi f(N),nf(N),c(N);
  dsu d(N);
  rep(i,M) {
    int a,b; cin >> a >> b;
    a--,b--;
    d.merge(a,b);
    f[a]++;
    f[b]++;
  }
  rep(i,K) {
    int a,b; cin >> a >> b;
    a--,b--;
    if (d.same(a,b)) {
      nf[a]++;
      nf[b]++;
    }
  }
  ll ans = 0;
  for (vi& group : d.groups()) {
    ll n = group.size();
    for (int i : group) c[i] = (n-1)-f[i]-nf[i];
  }
  rep(i,N) {
    if (i>0) cout << " ";
    cout << c[i];
  }
  cout << endl;
  return 0;
}

