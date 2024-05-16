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
  
  int H,W;
  cin >> H >> W;
  int sx,sy,gx,gy;
  cin >> sy >> sx >> gy >> gx;
  sx--, sy--, gx--, gy--;
  
  vi v(H*W);
  rep(i,H) {
    string s; cin >> s;
    assert(s.size()==W);
    rep(j,W) {
      v[i*W+j] = (s[j]=='.');
    }
  }
  vi d(H*W,-1);
  int start = sy*W+sx;
  int goal = gy*W+gx;
  queue<ii> que;
  auto rec = [&](int i, int c)->void {
    if (d[i]<0 and v[i]>0) {
      d[i] = c;
      que.emplace(i,c);
    }
  };
  rec(start,0);
  while (!que.empty()) {
    auto [i,c] = que.front();
    que.pop();
    c++;
    int x=i%W,y=i/W;
    if (x>0) rec(i-1,c);
    if (y>0) rec(i-W,c);
    if (x<W-1) rec(i+1,c);
    if (y<H-1) rec(i+W,c);
  }
  
  cout << d[goal] << endl;
  return 0;
}

