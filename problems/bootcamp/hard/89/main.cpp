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
#define debug(x) cout << #x << ": " << x << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vi t(3);
  mint ans=1;
  rep2e(i,1,N) {
    int a; cin >> a;
    int c=0;
    rep(j,3) {
      if (t[j]==a) {
        if (++c==1) t[j]++;
      }
    }
    ans *= c;
  }
  cout << ans.val() << endl;
  return 0;
}

