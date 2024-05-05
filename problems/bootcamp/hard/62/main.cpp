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
  const int HW = H*W;
  vector<bool> v(HW);
  for (int i=0; i<H; i++) {
    string s; cin >> s;
    for (int j=0; j<W; j++) {
      int k = i*W+j;
      v[k] = s[j]=='.';
    }
  }
  vector<vector<int>> d(HW,vector<int>(4));
  for (int i=0; i<H; i++) {
    int left=0,right=0;
    for (int j=0; j<W; j++) {
      int kl = i*W+j;
      int kr = i*W+(W-1-j);
      if (v[kl]) d[kl][0] = ++left; else left=0;
      if (v[kr]) d[kr][1] = ++right; else right=0;
    }
  }
  for (int j=0; j<W; j++) {
    int up=0,down=0;
    for (int i=0; i<H; i++) {
      int ku = i*W+j;
      int kd = (H-1-i)*W+j;
      if (v[ku]) d[ku][2] = ++up; else up=0;
      if (v[kd]) d[kd][3] = ++down; else down=0;
    }
  }
  int ans = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int k = i*W+j;
      if (!v[k]) continue;
      int t = d[k][0]+d[k][1]+d[k][2]+d[k][3]-3;
      ans = max(ans, t);
    }
  }
  
  cout << ans << endl;
  return 0;
}

