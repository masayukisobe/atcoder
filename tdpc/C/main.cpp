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

double prob(double diff) {
  return 1.0/(1.0+pow(10,diff/400.0));
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int K;
  cin >> K;
  int N = 1<<K;
  vi R(N);
  rep(i,N) cin >> R[i];
  cout << fixed << setprecision(10);
  vector<double> v0(N,1.0),v1(N);
  rep2e(k,1,K) {
    auto &P = k%2==1 ? v0 : v1;
    auto &Q = k%2==0 ? v0 : v1;
    rep(i,N) {
      double win = 0.0;
      rep(j,N) {
        if ((i>>k)==(j>>k) && (i>>(k-1))!=(j>>(k-1))) {
          win += P[j]*prob(R[j]-R[i]);
        }
      }
      Q[i] = P[i]*win;
      if (k==K) cout << Q[i] << endl;
    }
  }
  return 0;
}

