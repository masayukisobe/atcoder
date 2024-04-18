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

const int inf = (1<<30);

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W;
  cin >> H >> W;
  int si,sj,gi,gj;
  cin >> si >> sj >> gi >> gj;
  si--, sj--, gi--, gj--;
  
  vector<bool> wall(H*W);
  for (int i=0; i<H; i++) {
    string s;
    cin >> s;
    assert(s.size()==W);
    for (int j=0; j<W; j++) {
      wall[i*W+j] = (s[j]=='#');
    }
  }
  // 0,1,2,3 = left, right, up, down
  vector<vector<int>> dp(H*W,vector<int>(4,inf));

  queue<int> que;
  int sk = si*W+sj;
  for (int i=0; i<4; i++) dp[sk][i]=0;
  que.push(sk);

  while (!que.empty()) {
    //cout << que.size() << endl;
    int k = que.front();
    que.pop();
    int i = k/W, j = k%W;
    //cout << i << "," << j << endl;
    int costs[4] = {0,0,0,0};
    for (int t1=0; t1<4; t1++) {
      int keep = dp[k][t1];
      int turn = inf;
      for (int t2=0; t2<4; t2++) {
        if (t1!=t2) turn = min(turn,dp[k][t2]+1);
      }
      costs[t1] = min(keep,turn);
    }
    
    // left
    if (j>0 && !wall[k-1] && dp[k-1][0]>costs[0]) {
      dp[k-1][0] = costs[0];
      que.push(k-1);
    }
    // right
    if (j<W-1 && !wall[k+1] && dp[k+1][1]>costs[1]) {
      dp[k+1][1] = costs[1];
      que.push(k+1);
    }
    // up
    if (i>0 && !wall[k-W] && dp[k-W][2]>costs[2]) {
      dp[k-W][2] = costs[2];
      que.push(k-W);
    }
    // down
    if (i<H-1 && !wall[k+W] && dp[k+W][3]>costs[3]) {
      dp[k+W][3] = costs[3];
      que.push(k+W);
    }
  }

  int ans = inf;
  int gk = gi*W+gj;
  for (int t=0; t<4; t++) {
    ans = min(ans,dp[gk][t]);
  }
  cout << ans << endl;
  return 0;
}

