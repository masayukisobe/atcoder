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
  cin >> N;
  int ans = 0;
  int smax = 0;
  vector<bool> dp(10001);
  dp[0] = true;
  for (int i=0; i<N; i++) {
    int s; cin >> s;
    for (int j=smax; j>=0; j--) {
      if (dp[j]) {
        int k = j+s;
        dp[k] = true;
        smax = max(k,smax);
        if (k%10>0) ans = max(k,ans);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

