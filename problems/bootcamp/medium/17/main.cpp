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
  ll T;
  cin >> N >> T;
  ll ans = 0;
  ll tend = 0;
  for (int i=0; i<N; i++) {
    ll t; cin >> t;
    if (t<tend) {
      ans -= tend-t;
    }
    ans += T;
    tend = t+T;
  }
  cout << ans << endl;
  return 0;
}

