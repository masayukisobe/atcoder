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
    int n,k;
    cin >> n >> k; n--;
    e[n].resize(k);
    rep(j,k) {
      cin >> e[n][j];
      e[n][j]--;
    }
    sort(e[n].begin(),e[n].end());
  }
  vector<ii> ts(N);
  int t=0;
  auto dfs = [&](auto& dfs, int i)->void{
    ts[i].first=++t;
    for (int j: e[i]) {
      if (ts[j].first==0) dfs(dfs,j);
    }
    ts[i].second=++t;
  };
  rep(i,N) {
    if (ts[i].first==0) dfs(dfs,i);
  }
  rep(i,N) {
    cout << (i+1) << " " << ts[i].first << " " << ts[i].second << endl;
  }
  return 0;
}

