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
  
  ll N,K;
  cin >> N >> K;
  if (K==0) {
    cout << N*N << endl;
    return 0;
  }
  ll ans = 0;
  for (ll b=K+1; b<=N; b++) {
    ll c = N/b;
    ans += c * (b-K);
    ll r = N%b;
    if (r>=K) ans += r-K+1;
  }
  cout << ans << endl;
  return 0;
}

