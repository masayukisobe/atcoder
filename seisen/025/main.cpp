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

bool solve() {
  int W,H;
  cin >> W >> H;
  if (W==0 and H==0) return false;
  vi v(H*W);
  rep(i,H) rep(j,W) cin >> v[i*W+j];
  
  vi c(H*W);
  auto dfs = [&](auto& dfs, int i, int n) -> void {
    if (v[i]==0 or c[i]>0) return;
    c[i] = n;
    int x=i%W,y=i/W;
    if (x>0) dfs(dfs,i-1,n);
    if (y>0) dfs(dfs,i-W,n);
    if (x<W-1) dfs(dfs,i+1,n);
    if (y<H-1) dfs(dfs,i+W,n);
    if (x>0 and y>0) dfs(dfs,i-W-1,n);
    if (x>0 and y<H-1) dfs(dfs,i+W-1,n);
    if (x<W-1 and y>0) dfs(dfs,i-W+1,n);
    if (x<W-1 and y<H-1) dfs(dfs,i+W+1,n);
  };
  int num=0;
  rep(i,H*W) {
    if (v[i]>0 and c[i]==0) dfs(dfs,i,++num);
  }
  cout << num << endl;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  while (solve()) continue;
  return 0;
}
  
