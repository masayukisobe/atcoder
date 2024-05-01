// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W;
  cin >> H >> W;
  vector<int> C(100);
  for (int i=0; i<100; i++) cin >> C[i];
  for (int k=0; k<=9; k++) {
    for (int i=0; i<=9; i++) {
      for (int j=0; j<=9; j++) {
        int ij = i*10+j;
        int ik = i*10+k;
        int kj = k*10+j;
        C[ij] = min(C[ij],C[ik]+C[kj]);
      }
    }
  }

  ll ans = 0;
  for (int i=0; i<H*W; i++) {
    int a; cin >> a;
    ans += C[a*10+1];
  }
  cout << ans << endl;
  return 0;
}

