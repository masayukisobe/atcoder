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
  vector<bool> v(H*W);
  int walls = 0;
  for (int i=0; i<H; i++) {
    string s; cin >> s;
    for (int j=0; j<W; j++) {
      int k = i*W+j;
      v[k]=bool(s[j]=='.');
      if (!v[k]) walls++;
    }
  }
  //cout << walls << endl;
  vector<vector<int>> e(H*W);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int k = i*W+j;
      if (!v[k]) continue;
      if (j>0 && v[k-1]) e[k].push_back(k-1);
      if (i>0 && v[k-W]) e[k].push_back(k-W);
      if (j<W-1 && v[k+1]) e[k].push_back(k+1);
      if (i<H-1 && v[k+W]) e[k].push_back(k+W);
    }
  }
  const int inf = (1<<30);
  vector<int> best(H*W,inf);
  auto dfs =
    [&](auto& self,int i,int d) -> void {
      if (best[i]>d) {
        best[i] = d;
      } else return;
      for (auto j : e[i]) {
        self(self,j,d+1);
      }
    };
  const int start = 0;
  const int goal = H*W-1;
  dfs(dfs,start,1);
  //cout << best[goal] << endl;
  int ans = (best[goal]<inf) ? (H*W - best[goal] - walls) : -1;
  cout << ans << endl;
  return 0;
}

