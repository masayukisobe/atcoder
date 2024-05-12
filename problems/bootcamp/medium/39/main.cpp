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

ll solve(ll K, ll A, ll B) {
  if (K<A-1) return K+1;
  K-=A-1;
  ll r=A, n=K/2, m=K%2;
  r += n*max(2LL,B-A)+m;
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll K,A,B;
  cin >> K >> A >> B;
  cout << solve(K,A,B) << endl;
  return 0;
}

