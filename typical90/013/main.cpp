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

const ll inf = (1LL<<60);

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int,ll>>> e(N);
  for (int i=0; i<M; i++) {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--,b--;
    e[a].emplace_back(b,c);
    e[b].emplace_back(a,c);
  }
  int terminal[2] = {0,N-1};
  vector<vector<ll>> dp(2,vector<ll>(N,inf));
  for (int i=0; i<2; i++) {
    queue<pair<int,ll>> que;
    dp[i][terminal[i]]=0;
    que.emplace(terminal[i],0);
    while (!que.empty()) {
      auto [x,d] = que.front();
      que.pop();
      for (auto& [y,c] : e[x]) {
        if (dp[i][y]>d+c) {
          dp[i][y] = d+c;
          que.emplace(y,d+c);
        }
      }
    }
  }
  for (int i=0; i<N; i++) {
    cout << dp[0][i]+dp[1][i] << endl;
  }
  return 0;
}

