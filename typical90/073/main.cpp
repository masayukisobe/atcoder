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

#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;

int N;
char node[100009];
vector<vector<int>> edge;

// [0] = subtree pattens when root is only a
// [1] = subtree pattens when root is only b
// [2] = subtree pattens when root has both a,b
mint dp[3][100009];

void dfs(int i, int pre) {
  for (int j : edge[i]) {
    if (j!=pre) dfs(j,i);
  }
  char current = node[i];
  if (current=='a') {
    dp[0][i] = 1;
    dp[1][i] = 0;
    dp[2][i] = 1;
    for (int j : edge[i]) {
      if (j==pre) continue;
      mint only_a = 0;
      only_a += dp[0][j]; // connect
      only_a += dp[2][j]; // cut
      dp[0][i] *= only_a;
      mint both_and_only_a = 0;
      both_and_only_a += dp[0][j]; // connect
      both_and_only_a += dp[1][j]; // connect
      both_and_only_a += 2*dp[2][j]; // connect + cut
      dp[2][i] *= both_and_only_a;
    }
    // both = both_and_only_a - only_a
    dp[2][i] -= dp[0][i];
  } else if (current=='b') {
    dp[0][i] = 0;
    dp[1][i] = 1;
    dp[2][i] = 1;
    for (int j : edge[i]) {
      if (j==pre) continue;
      mint only_b = 0;
      only_b += dp[1][j]; // connect
      only_b += dp[2][j]; // cut
      dp[1][i] *= only_b;
      mint both_and_only_b = 0;
      both_and_only_b += dp[0][j]; // connect
      both_and_only_b += dp[1][j]; // connect
      both_and_only_b += 2*dp[2][j]; // connect + cut
      dp[2][i] *= both_and_only_b;
    }
    // both = both_and_only_b - only_b
    dp[2][i] -= dp[1][i];
  } else {
    assert(false);
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> node[i];
  }
  edge.resize(N);
  for (int i=0; i<N-1; i++) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(0,-1);
  cout << dp[2][0].val() << endl;
  return 0;
}

