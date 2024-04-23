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

int dp[5009][5009];
int ab[5009][5009];

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  cin >> N >> K;
  int ma=K+1,mb=K+1;
  for (int i=0; i<N; i++) {
    int a,b; cin >> a >> b;
    ab[a][b]++;
    ma = max(ma,a);
    mb = max(mb,b);
  }
  for (int a=1; a<=ma; a++) {
    for (int b=1; b<=mb; b++) {
      dp[a][b] = ab[a][b]+dp[a-1][b]+dp[a][b-1]-dp[a-1][b-1];
    }
  }
  int ans = 0;
  for (int a=1; a+K<=ma; a++) {
    for (int b=1; b+K<=mb; b++) {
      int n = dp[a+K][b+K]-dp[a+K][b-1]-dp[a-1][b+K]+dp[a-1][b-1];
      ans = max(ans,n);
    }
  }
  cout << ans << endl;
  return 0;
}

