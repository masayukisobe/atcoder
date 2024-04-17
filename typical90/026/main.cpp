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

  int N;
  cin >> N;
  
  vector<vector<int>> edge(N,vector<int>());
  for (int i=0; i<N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  
  vector<int> color(N); // 0: no color, 1:white, 2:black
  auto dfs =
    [&N,&edge,&color](auto self, int i, int k) -> void {
      color[i] = k;
      for (int j : edge[i]) {
        if (color[j]==0) {
          self(self, j, 3-k);
        }
      }
    };

  dfs(dfs, 0, 1);
  vector<int> white, black;
  for (int i=0; i<N; i++) {
    if (color[i]==1) white.push_back(i);
    if (color[i]==2) black.push_back(i);
  }

  vector<int>& selected = (white.size()>black.size() ? white : black);
  sort(selected.begin(), selected.end());
  for (int i=0; i<N/2; i++) {
    if (i>0) cout << " ";
    cout << selected[i]+1;
  }
  cout << endl;
  return 0;
}

