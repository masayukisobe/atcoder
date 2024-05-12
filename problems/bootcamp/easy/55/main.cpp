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
#define debug(x) cout << _(x) << endl
#define debug2(x,y) cout << _(x) << _(y) << endl
#define debug3(x,y,z) cout << _(x) << _(y) << _(z) << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

bool check(const int D, const vll &x, const vll &y) {
  ll d = 0;
  rep(i,D) {
    ll dx=abs(x[i]-y[i]);
    d += dx*dx;
  }
  ll p=0;
  while (p*p<d) p++;
  return p*p==d;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N,D;
  cin >> N >> D;
  vector<vll> x(N,vll(D));
  rep(i,N) rep(j,D) cin >> x[i][j];
  ll ans = 0;
  rep(i,N) rep(j,N) if (i<j) {
    bool c=check(D,x[i],x[j]);
    //debug3(i,j,c);
    ans += c;
  }
  cout << ans << endl;
  return 0;
}

