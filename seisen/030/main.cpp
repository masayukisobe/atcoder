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
  
  int H,W,N;
  cin >> H >> W >> N;
  vi v(H*W);
  vi w(N+1,-1);
  rep(i,H) {
    string s; cin >> s;
    assert(s.size()==W);
    rep(j,W) {
      char c=s[j];
      int k=i*W+j;
      if (c=='.') {
        v[k] = 1;
      } else if (c=='S') {
        v[k] = 1;
        w[0] = k;
      } else if (c=='X') {
        v[k] = 0;
      } else {
        assert(c>='1' and c<='9');
        v[k] = 1;
        w[(c-'0')] = k;
      }
    }
  }
  rep(i,N+1) assert(w[i]>=0);

  vi d(H*W);
  queue<ii> que;
  auto init = [&]() {
    queue<ii> empty;
    swap(que,empty);
    fill(d.begin(),d.end(),-1);
  };
  auto rec = [&](int i, int c) {
    if (d[i]<0 and v[i]>0) {
      d[i] = c;
      que.emplace(i,c);
    }
  };

  ll ans = 0;
  rep2e(i,1,N) {
    init();
    rec(w[i-1],0);
    while (!que.empty()) {
      auto [j,c] = que.front();
      que.pop();
      if (j==w[i]) {
        ans += c;
        break;
      }
      int x=j%W,y=j/W;
      c++;
      if (x>0) rec(j-1,c);
      if (y>0) rec(j-W,c);
      if (x<W-1) rec(j+1,c);
      if (y<H-1) rec(j+W,c);
    }
  }
  cout << ans << endl;
  return 0;
}

