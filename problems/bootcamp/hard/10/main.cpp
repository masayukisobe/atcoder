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

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> a(N+1);
  a[0] = 0;
  for (int i=1; i<=N; i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  ll ans = 0;
  for (int i=1; i<=N; i++) {
    auto it = lower_bound(a.begin()+i,a.end(),a[i-1]+K);
    if (it!=a.end()) {
      ans += (ll)(a.end()-it);
    }
  }
  cout << ans << endl;
  return 0;
}

