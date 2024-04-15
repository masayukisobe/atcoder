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
  
  int N;
  cin >> N;
  vector<ll> dp(N+1);
  for (int i=1; i<=N; i++) {
    ll a;
    cin >> a;
    dp[i] = dp[i-1]+a;
  }
  ll z = dp[N];
  if (z%10!=0) {
    cout << "No" << endl;
    return 0;
  }
  ll d = z/10;
  for (int i=0; i<N; i++) {
    ll c = dp[i]+d;
    if (c>z) c-=z;
    auto it = lb(dp.begin(),dp.end(),c);
    if (it!=dp.end() && (*it)==c) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

