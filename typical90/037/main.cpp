// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#include <atcoder/all>
using namespace atcoder;

ll _id() { return -1LL; }
ll _max(ll a, ll b) { return max(a,b); }


int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,W;
  cin >> W >> N;

  segtree<ll,_max,_id> dp(W+1);
  vector<ll> temp(W+1);
  dp.set(0,0);
  for (ll i=0; i<N; i++) {
    int l,r;
    ll v;
    cin >> l >> r >> v;
    for (int j=l; j<=W; j++) {
      int a = max(0,j-r);
      int b = max(0,j-l);
      ll m = dp.prod(a,b+1);
      temp[j] = (m>=0 ? m+v : -1LL);
    }
    for (int j=l; j<=W; j++) {
      ll m = temp[j];
      if (m>=0 && m>dp.get(j)) dp.set(j,m);
    }
  }
  cout << dp.get(W) << endl;
  return 0;
}

