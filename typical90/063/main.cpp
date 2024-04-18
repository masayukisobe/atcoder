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

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H, W;
  cin >> H >> W;
  vector<vector<int>> p(H,vector<int>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> p[i][j];
    }
  }
  int ans = 0;
  int rows[8];
  int cols[10001];
  for (int m=1; m<(1<<H); m++) {
    int mask = m;
    int i=0,nr=0;
    while (mask>0) {
      if (mask&1) rows[nr++]=i;
      i++, mask>>=1;
    }
    assert(nr>0 && nr<=H);
    int nc=0;
    for (int j=0; j<W; j++) {
      int q = p[rows[0]][j];
      bool fill = true;
      for (int i=0; i<nr; i++) {
        if (p[rows[i]][j]!=q) {
          fill = false;
          break;
        }
      }
      if (fill) {
        cols[nc++] = q;
      }
    }
    
    sort(cols,cols+nc);
    int w=0,maxw=0;
    for (int j=0; j<nc; j++) {
      if (j>0 && cols[j-1]==cols[j])
        w++;
      else
        w=1;
      maxw = max(w,maxw);
    }
    ans = max(ans, nr * maxw);
  }
  cout << ans << endl;
  return 0;
}

