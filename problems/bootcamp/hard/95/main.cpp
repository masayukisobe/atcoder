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
  vll A(N);
  rep(i,N) cin>>A[i];

  mint ans=0,n=1;
  rep(i,60) {
    mint one=0,zero=0;
    ll mask = 1LL<<i;
    for(ll a:A) {
      if (a&mask) one++; else zero++;
    }
    ans += one*zero*n;
    n *= 2;
  }
  
  cout << ans.val() << endl;
  return 0;
}

