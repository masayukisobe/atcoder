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
  vector<vector<ll>> dp(2,vector<ll>(N+1));
  for (int i=1; i<=N; i++) {
    int c,p;
    cin >> c >> p;
    dp[c-1][i] = dp[c-1][i-1]+p;
    dp[2-c][i] = dp[2-c][i-1];
  }
  int Q;
  cin >> Q;
  for (int i=1; i<=Q; i++) {
    int l,r;
    cin >> l >> r;
    cout << dp[0][r]-dp[0][l-1];
    cout << " ";
    cout << dp[1][r]-dp[1][l-1];
    cout << endl;
  }
  return 0;
}

