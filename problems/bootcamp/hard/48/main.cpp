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
  
  int H, N;
  cin >> H >> N;

  vector<int> dp(H+1,-1);
  dp[0] = 0;
  for (int i=0; i<N; i++) {
    int a,b; cin >> a >> b;
    for (int h=0; h<=H; h++) {
      if (dp[h]<0) continue;
      int h1 = min(h+a,H);
      if (dp[h1]<0 || dp[h1]>dp[h]+b) {
        dp[h1] = dp[h]+b;
      }
    }
  }
  cout << dp[H] << endl;
  return 0;
}

