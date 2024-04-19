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

int H,W;
char world[300];

int dfs(int depth, int k) {
  //debug(depth); debug(k);
  if (depth>0 && world[k]=='s') return depth;
  int i=k/W, j=k%W, r=0;
  world[k] = (depth>0 ? '#' : 's');
  if (i>0 && world[k-W]!='#') {
    r = max(r,dfs(depth+1,k-W));
  }
  if (i<H-1 && world[k+W]!='#') {
    r = max(r,dfs(depth+1,k+W));
  }
  if (j>0 && world[k-1]!='#') {
    r = max(r,dfs(depth+1,k-1));
  }
  if (j<W-1 && world[k+1]!='#') {
    r = max(r,dfs(depth+1,k+1));
  }
  world[k] = '.';
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> H >> W;
  for (int i=0; i<H; i++) {
    string s;
    cin >> s;
    assert(s.size()==W);
    for (int j=0; j<W; j++) {
      world[i*W+j] = s[j];
    }
  }
  int ans = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int k=i*W+j;
      if (world[k]=='.') {
        ans = max(ans,dfs(0,k));
      }
    }
  }
  cout << (ans < 3 ? -1 : ans) << endl;
  return 0;
}

