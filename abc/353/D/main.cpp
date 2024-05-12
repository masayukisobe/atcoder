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

using mint = modint998244353;

ll pw10(ll n) {
  ll ret=1;
  rep(i,n) ret*=10;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vll a(N);
  vll b(N);  
  vll dp1(N);
  vll dp2(N);
  rep(i,N) {
    string s;
    cin >> s;
    a[i] = stoi(s);
    b[i] = pw10(s.size());
    //debug(a[i]);debug(b[i]);
    
    dp1[i] = a[i];
    dp2[i] = b[i];
    if (i>0) {
      dp1[i]+=dp1[i-1];
      dp2[i]+=dp2[i-1];
    }
  }
  mint ans=0;
  for (int i=0; i<N; i++) {
    mint x = dp2[N-1]-dp2[i];
    mint y = dp1[N-1]-dp1[i];
    //debug(i); debug(x.val()); debug(y.val());
    x *= a[i];
    ans += x+y;
  }
  
  cout << ans.val() << endl;
  return 0;
}

