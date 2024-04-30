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

  ll ans = 0;
  int N,K;
  cin >> N >> K;
  if (K%2==0) {
    ll r = N/K;
    ans += r*r*r;
    if (N>=K*r+K/2) r++;
    ans += r*r*r;
  } else {
    ll r = N/K;
    ans += r*r*r;
  }
  cout << ans << endl;
  return 0;
}

