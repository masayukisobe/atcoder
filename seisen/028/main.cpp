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
#define _(x) #x << "=" << x << " "
#define debug(x) cerr << _(x) << endl
#define debug2(x,y) cerr << _(x) << _(y) << endl
#define debug3(x,y,z) cerr << _(x) << _(y) << _(z) << endl
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
  
  int N;
  cin >> N;
  vvi e(N);
  rep(i,N) {
    int u,k; cin >> u >> k; u--;
    e[u].resize(k);
    rep(j,k) {
      cin >> e[u][j];
      e[u][j]--;
    }
  }
  vi d(N,-1);
  queue<ii> que;
  d[0] = 0;
  que.emplace(0,0);
  while (!que.empty()) {
    auto [i,c]=que.front();
    que.pop();
    c++;
    for (int j:e[i]) {
      if (d[j]<0) {
        d[j] = c;
        que.emplace(j,c);
      }
    }
  }
  rep(i,N) cout << (i+1) << " " << d[i] << endl;
  return 0;
}

