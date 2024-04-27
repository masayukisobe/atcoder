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

void rep(int n, char c) {
  for (int i=0; i<n; i++) {
    cout << c;
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  int ans = 0;
  rep(ty-sy,'U');
  rep(tx-sx,'R');
  rep(ty-sy,'D');
  rep(tx-sx,'L');
  rep(1,'L');
  rep(ty-sy+1,'U');
  rep(tx-sx+1,'R');
  rep(1,'D');
  rep(1,'R');
  rep(ty-sy+1,'D');
  rep(tx-sx+1,'L');
  rep(1,'U');
  cout << endl;
  return 0;
}

