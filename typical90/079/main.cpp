// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define lb lower_bound
#define ub upper_bound

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W;
  cin >> H >> W;
  int N = H*W;
  vector<int> a(N);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> a[i*W+j];
    }
  }
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int x;
      cin >> x;
      a[i*W+j] -= x;
    }
  }
  ll ans=0;
  for (int i=0; i+1<H; i++) {
    for (int j=0; j+1<W; j++) {
      int k = i*W+j;
      int x = a[k];
      if (x!=0) {
        ans += abs(x);
        a[k] -= x;
        a[k+1] -= x;
        a[k+W] -= x;
        a[k+W+1] -= x;
      }
    }
  }
  for (int k=0; k<N; k++) {
    if (a[k]!=0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;
  return 0;
}

