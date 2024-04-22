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
int c[10009];
char m[10009];

void dfs(int cost, int pos, char pre) {
  char curr = m[pos];
  int cost1 = cost+int(pre=='.' and curr=='#');
  if (c[pos]>=0 && c[pos]<=cost1) {
    return;
  }
  c[pos] = cost1;
  
  int i = pos/W, j = pos%W;
  if (i<H-1) dfs(cost1,pos+W,curr);
  if (j<W-1) dfs(cost1,pos+1,curr);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> H >> W;
  for (int i=0; i<H; i++) {
    string s; cin >> s;
    assert(s.size()==W);
    for (int j=0; j<W; j++) {
      m[i*W+j] = s[j];
      c[i*W+j] = -1;
    }
  }
  dfs(0,0,'.');
  cout << c[H*W-1] << endl;
  return 0;
}

