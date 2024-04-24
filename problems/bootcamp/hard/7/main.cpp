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

using ll2 = pair<ll,ll>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll N,M;
  cin >> N >> M;
  vector<ll2> v;
  for (int i=0; i<N; i++) {
    ll x; cin >> x;
    v.emplace_back(x,1);
  }
  for (int i=0; i<M; i++) {
    ll b,c;
    cin >> b >> c;
    v.emplace_back(c,b);
  }
  sort(v.rbegin(),v.rend());
  ll ans = 0;
  for (auto& top : v) {
    //debug(top.first); debug(top.second);
    ll m = min(N,top.second);
    ans += top.first * m;
    N -= m;
    if (N==0) break;
  }
  cout << ans << endl;
  return 0;
}

