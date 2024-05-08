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
  
  int H,W;
  cin >> H >> W;
  vector<bool> A(H*W);
  rep(i,H) rep(j,W) {
    int a; cin >> a;
    A[i*W+j] = a%2==0;
  }

  vector<ii> B;
  B.reserve(H*W);
  bool even1=true;
  rep(i,H) {
    bool even2=true;
    rep(j,W) {
      int k = i*W+j;
      bool a = A[k];
      if (even2) {
        even2 = a;
      } else {
        assert(j>0);
        B.emplace_back(k-1,k);
        even2 = !a;
      }
    }
    if (even1) {
      even1 = even2;
    } else {
      assert(i>0);
      int k = i*W+(W-1);
      B.emplace_back(k-W,k);
      even1 = !even2;
    }
  }
  cout << B.size() << endl;
  for (auto [k1,k2] : B) {
    int i1=k1/W,j1=k1%W;
    int i2=k2/W,j2=k2%W;
    cout << i1+1 << " " << j1+1 << " " << i2+1 << " " << j2+1 << endl;
  }
  return 0;
}

