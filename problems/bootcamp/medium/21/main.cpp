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
#define debug(x) cout << #x << ": " << x << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

ll calc(ll n) {
  if (n<2) return 0;
  return n*(n-1)/2;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  
  int N;
  cin >> N;
  vll p(N+1);
  vll a(N);
  rep(i,N) {
    cin >> a[i];
    p[a[i]]++;
  }
  ll total = 0;
  rep2e(x,1,N) total += calc(p[x]);
  rep(i,N) {
    ll q = p[a[i]];
    cout << total-calc(q)+calc(q-1) << endl;
  }
  return 0;
}

