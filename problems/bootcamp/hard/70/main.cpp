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
  vector<int> A(N),B(N),C(N);
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<N; i++) cin >> B[i];
  for (int i=0; i<N; i++) cin >> C[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());

  vector<int> bc(N);
  for (int i=0; i<N; i++) {
    auto it = lower_bound(C.begin(),C.end(),B[i]+1);
    bc[i] = C.end()-it;
  }
  vector<ll> dp(N);
  for (int i=0; i<N; i++) {
    dp[i] = bc[i];
    if (i>0) dp[i] += dp[i-1];
  }
  
  ll ans = 0;
  for (int i=0; i<N; i++) {
    auto it = lower_bound(B.begin(),B.end(),A[i]+1);
    int j = it-B.begin();
    if (j<N) {
      ans += dp[N-1] - (j>0 ? dp[j-1] : 0);
    }
  }
  cout << ans << endl;
  return 0;
}

