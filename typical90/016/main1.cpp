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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll N;
  cin >> N;
  vector<ll> v(3);
  for (int i=0; i<3; i++) cin >> v[i];
  sort(v.begin(),v.end());
  ll A = v[0];
  ll B = v[1];
  ll C = v[2];
  
  ll ans = 10000;
  for (int i=0; i<=9999; i++) {
    for (int j=0; j<=9999 ; j++) {
      ll v = (ll)(i)*A+(ll)(j)*B;
      if (v>N) break;
      ll r = N-v;
      if (r%C==0) {
        ll k = r/C;
        ans = min(ans,i+j+k);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

