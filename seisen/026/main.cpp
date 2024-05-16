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
  
  int N,Q;
  cin >> N >> Q;
  vvi e(N);
  rep(i,N-1) {
    int a,b; cin >> a >> b; a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  vi c(N);
  rep(i,Q) {
    int p,x; cin >> p >> x; p--;
    c[p]+=x;
  }
  auto dfs = [&](auto& dfs, int i, int p, int n)->void {
    c[i] += n;
    for (int j : e[i]) {
      if (j!=p) {
        dfs(dfs,j,i,c[i]);
      }
    }
  };
  dfs(dfs,0,-1,0);
  rep(i,N) cout << c[i] << " ";
  cout << endl;
  return 0;
}

