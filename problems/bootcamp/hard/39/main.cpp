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
  string s;
  cin >> N;
  cin >> s;
  assert(s.size()==N);
  vector<int> dp(N+1);
  for (int i=0; i<N; i++) {
    dp[i+1] = dp[i] + int(s[i]=='#');
  }
  int ans = 1<<30;
  for (int i=0; i<=N; i++) {
    int left_black = dp[i]-dp[0];
    int right_black = dp[N]-dp[i];
    int right_length = N-i;
    int right_white = right_length - right_black;
    int cost = left_black + right_white;
    ans = min(ans,cost);
  }
  cout << ans << endl;
  return 0;
}

