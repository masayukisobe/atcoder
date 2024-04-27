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

int H,W;
int m[1002*1002];
int f[1002*1002];

int idx(int i, int j) { return i*(W+2)+j; }

int dfs(int i, int j, int orig) {
  int k = idx(i,j);
  if (f[k]==orig) return 0;
  f[k] = orig;
  if (m[k]==1) return 1;
  if (m[k]==2) return 0;
  int ret = 1;
  if (i>1) ret += dfs(i-1,j,orig);
  if (i<H) ret += dfs(i+1,j,orig);
  if (j>1) ret += dfs(i,j-1,orig);
  if (j<W) ret += dfs(i,j+1,orig);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> H >> W;
  for (int i=1; i<=H; i++) {
    string s; cin >> s;
    for (int j=1; j<=W; j++) {
      if (s[j-1]=='#') m[idx(i,j)] = 2;
    }
  }
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      int k = idx(i,j);
      if (m[k]==0) {
        if (m[idx(i-1,j)]==2) m[k]=1;
        if (m[idx(i+1,j)]==2) m[k]=1;
        if (m[idx(i,j-1)]==2) m[k]=1;
        if (m[idx(i,j+1)]==2) m[k]=1;
      }
    }
  }
  int ans = 0;
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      int k = idx(i,j);
      if (m[k]==1) {
        ans = max(1,ans);
      }
      if (m[k]==0 && f[k]==0) {
        //debug(i); debug(j); debug(-1);
        ans = max(ans,dfs(i,j,k));
      }
    }
  }
  cout << ans << endl;
  return 0;
}

