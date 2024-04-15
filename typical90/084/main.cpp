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
  
  int N;
  string s;
  cin >> N >> s;
  assert(N==s.size());
  
  vector<int> dp(N);
  for (int i=1; i<N; i++) {
    dp[i] = dp[i-1] + int(s[i-1]!=s[i]);
  }
  ll ans = 0;
  for (int i=0; i+1<N; i++) {
    auto it = lower_bound(dp.begin()+1,dp.end(),dp[i]+1);
    if (it!=dp.end()) ans += dp.end()-it;
  }
  cout << ans << endl;
  return 0;
}

