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

//#include <atcoder/all>
//using namespace atcoder;

const ll T=10000LL*10000LL;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vll a(N);
  ll s=0;
  rep(i,N) {
    cin>>a[i];
    s+=a[i];
  }
  sort(a.begin(),a.end());
  ll ans = 0;
  rep(i,N) {
    auto it=lower_bound(a.begin(),a.end(),T-a[i]);
    int j = it-a.begin();
    int n = N-j;
    if (i>=j) n--;
    //debug(i); debug(j); debug(n);
    ans += (s-a[i]) + a[i]*(N-1) - n*T;
    //debug(ans);
  }
  cout << ans/2 << endl;
  return 0;
}

