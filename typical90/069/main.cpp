// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define lb lower_bound
#define ub upper_bound

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

//#include <atcoder/all>
//using namespace atcoder;

const ll MOD = 1000000007LL;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll N,K;
  cin >> N >> K;
  ll ans = K%MOD;
  if (N>=2) {
    ll t = max(K-1,0LL)%MOD;
    ans = (ans*t)%MOD;
  }
  
  // then we need (K-2)^(N-2)
  ll k2 = max(K-2,0LL);
  ll n = max(N-2,0LL);
  ll p = 0;
  while (n>0) {
    if (n&1) {
      ll t=k2;
      for (int i=0; i<p; i++) {
        t = (t*t)%MOD;
      }
      ans = (ans*t)%MOD;
    }
    n>>=1;
    p++;
  }
  cout << ans << endl;
  return 0;
}

