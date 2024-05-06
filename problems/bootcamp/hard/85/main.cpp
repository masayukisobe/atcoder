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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vi x(N),y(N);
  vll h(N);
  rep(i,N) cin >> x[i] >> y[i] >> h[i];
  rep2e(cx,0,100) rep2e(cy,0,100) {
    ll ub=LL_INF,lb=0;
    rep(i,N) {
      ll t = h[i]+abs(x[i]-cx)+abs(y[i]-cy);
      if (h[i]==0) ub = min(ub,t);
      else if (lb==0) lb = t;
      else if (lb!=t) {
        lb = 0;
        break;
      }
    }
    if (ub>=lb and lb>=1) {
      cout << cx << " " << cy << " " << lb << endl;
      return 0;
    }
  }
  return 0;
}

