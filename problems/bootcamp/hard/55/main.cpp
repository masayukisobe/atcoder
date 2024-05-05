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
  ll A,B;
  cin >> N >> A >> B;
  vector<ll> x(N);
  for (int i=0; i<N; i++) cin >> x[i];
  ll ans = 0;
  for (int i=1; i<N; i++) {
    ll d = x[i]-x[i-1];
    ans += min(d*A,B);
  }
  cout << ans << endl;
  return 0;
}

