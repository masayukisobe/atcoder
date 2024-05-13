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
  
  int N;
  cin >> N;
  vi x(N),y(N);
  rep(i,N) cin >> y[i] >> x[i];

  vi P(8);
  iota(P.begin(),P.end(),0);
  
  do {
    // check input condition
    bool ok=true;
    rep(i,N) {
      if (P[y[i]]!=x[i]) {
        ok=false; break;
      }
    }
    if (!ok) continue;

    // check placement
    ok=true;
    rep(i,7) {
      int diag1=i+P[i];
      int diag2=i-P[i];
      rep2(j,i+1,8) {
        int diag3=j+P[j];
        int diag4=j-P[j];
        if (diag1==diag3 or diag2==diag4) {
          ok=false;
          break;
        }
      }
    }
    if (ok) {
      rep(i,8) {
        rep(j,8) {
          cout << (j==P[i] ? 'Q' : '.');
        }
        cout << endl;
      }
      return 0;
    }
  } while (next_permutation(P.begin(),P.end()));
  return 0;
}

