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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int D,N,M;
  cin >> D >> N >> M;
  
  vi s(N);
  rep(i,N-1) cin >> s[i+1];
  sort(s.begin(),s.end());

  ll ans = 0;
  rep(i,M) {
    int k; cin >> k;
    auto it = lower_bound(s.begin(),s.end(),k);
    int d1 = (it==s.end() ? s[0]+D : (*it));
    int d2 = (it==s.begin() ? s[N-1]-D : *(it-1));
    assert(d1>=k and k>=d2);
    ans += min((d1-k)%D,(k-d2)%D);
  }
  cout << ans << endl;
  return 0;
}

