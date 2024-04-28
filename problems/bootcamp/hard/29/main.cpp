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
  vector<ll> A(N);
  vector<ll> dp(N);
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A.begin(),A.end());
  for (int i=0; i<N; i++) {
    dp[i] = A[i];
    if (i>0) dp[i]+=dp[i-1];
  }
  int ans = 1;
  for (int i=N-2; i>=0; i--) {
    if (dp[i]*2>=A[i+1]) {
      ans++;
    } else break;
  }
  cout << ans << endl;
  return 0;
}

