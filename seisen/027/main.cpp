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
  
  int W,H;
  cin >> W >> H;
  vi v(H*W);
  rep(i,H) rep(j,W) cin >> v[i*W+j];

  int ans=0;
  auto dfs = [&](auto& dfs, int i, int d)->void {
    if (v[i]==0) return;
    v[i]=0;
    {
      ans = max(d,ans);
      d++;
      int x=i%W,y=i/W;
      if (x>0) dfs(dfs,i-1,d);
      if (y>0) dfs(dfs,i-W,d);
      if (x<W-1) dfs(dfs,i+1,d);
      if (y<H-1) dfs(dfs,i+W,d);
    }
    v[i]=1;
  };
  rep(i,H*W) dfs(dfs,i,1);
  cout << ans << endl;
  return 0;
}

