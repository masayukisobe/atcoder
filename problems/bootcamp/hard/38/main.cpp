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
  vector<bool> wall(H*W);
  for (int i=0; i<H; i++) {
    string s; cin >> s;
    for (int j=0; j<W; j++) {
      int k = i*W+j;
      if (s[j]=='#') wall[k]=true;
    }
  }
  vector<vector<int>> e(H*W);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int k = i*W+j;
      if (wall[k]) continue;
      if (j>0 && !wall[k-1]) e[k].push_back(k-1);
      if (i>0 && !wall[k-W]) e[k].push_back(k-W);
      if (j<W-1 && !wall[k+1]) e[k].push_back(k+1);
      if (i<H-1 && !wall[k+W]) e[k].push_back(k+W);
    }
  }

  vector<int> depth(H*W);
  auto dfs =
    [&](auto& self,int d,int i) -> void {
      if (depth[i]>=0 && d>=depth[i]) return;
      depth[i] = d;
      for (int j : e[i]) self(self,d+1,j);
    };

  int ans = 0;
  for (int k=0; k<H*W; k++) {
    if (!wall[k]) {
      fill(depth.begin(),depth.end(),-1);
      dfs(dfs,0,k);
      auto it = max_element(depth.begin(),depth.end());
      ans = max(*it,ans);
    }
  }
  cout << ans << endl;
  return 0;
}

