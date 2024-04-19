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

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll K;
  cin >> K;
  if (K==1) {
    cout << 1 << endl;
    return 0;
  }
  vector<ll> pp;
  for (ll p=1; p*p<=K; p++) {
    if (K%p>0) continue;
    pp.push_back(p);
    if (p!=K/p) pp.push_back(K/p);
  }
  sort(pp.begin(), pp.end());
  ll ans=0;
  for (ll i=0; i<pp.size(); i++) {
    ll a = pp[i]; // minimum factor
    ll Ka = K/a;
    for (ll j=i; j<pp.size(); j++) {
      ll b = pp[j]; // second minimum
      if (Ka%b==0LL) {
        ll c = Ka/b;
        if (b <= c) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

