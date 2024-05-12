// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define endl '\n'
#define _(x) #x << "=" << x << " "
#define debug(x) cout << _(x) << endl
#define debug2(x,y) cout << _(x) << _(y) << endl
#define debug3(x,y,z) cout << _(x) << _(y) << _(z) << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W,N;
  cin >> H >> W >> N;
  const int H2=H+2;
  const int W2=W+2;
  vll dp(H2*W2);
  rep(i,N) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    dp[a*W2+b]++;
    dp[a*W2+(d+1)]--;
    dp[(c+1)*W2+b]--;
    dp[(c+1)*W2+(d+1)]++;
  }
  rep2e(i,1,H) {
    rep2e(j,1,W) {
      int k = i*W2+j;
      dp[k]+=dp[k-1];
    }
  }
  rep2e(i,1,H) {
    rep2e(j,1,W) {
      int k = i*W2+j;
      dp[k]+=dp[k-W2];
    }
  }
  rep2e(i,1,H) {
    rep2e(j,1,W) {
      cout << dp[i*W2+j] << " ";
    }
    cout << endl;
  }
  return 0;
}

