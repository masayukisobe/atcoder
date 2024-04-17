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

int dp[1024][1024];

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;

  for (int i=0; i<N; i++) {
    int lx,ly,rx,ry;
    cin >> lx >> ly >> rx >> ry;
    dp[ly][lx]++;
    dp[ly][rx]--;
    dp[ry][lx]--;
    dp[ry][rx]++;
  }
  for (int y=0; y<=1000; y++) {
    for (int x=1; x<=1000; x++) {
      dp[y][x] += dp[y][x-1];
    }
  }
  for (int x=0; x<=1000; x++) {
    for (int y=1; y<=1000; y++) {
      dp[y][x] += dp[y-1][x];
    }
  }
  vector<int> count(N+1);
  for (int y=0; y<=1000; y++) {
    for (int x=0; x<=1000; x++) {
      count[dp[y][x]]++;
    }
  }
  for (int k=1; k<=N; k++) {
    cout << count[k] << endl;
  }
  return 0;
}

