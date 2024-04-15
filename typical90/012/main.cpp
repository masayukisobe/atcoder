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

#include <atcoder/all>
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W;
  cin >> H >> W;
  int N = H*W;
  dsu graph(N);
  int Q;
  cin >> Q;
  vector<bool> red(N);
  for (int i=0; i<Q; i++) {
    int t;
    cin >> t;
    if (t==1) {
      int r,c;
      cin >> r >> c;
      r--, c--;
      int k = r*W+c;
      red[k] = true;
      if (r>0 && red[k-W]) graph.merge(k,k-W);
      if (r<H-1 && red[k+W]) graph.merge(k,k+W);
      if (c>0 && red[k-1]) graph.merge(k,k-1);
      if (c<W-1 && red[k+1]) graph.merge(k,k+1);
    } else if (t==2) {
      int ra,ca,rb,cb;
      cin >> ra >> ca >> rb >> cb;
      ra--, ca--, rb--, cb--;
      int ka = ra*W+ca;
      int kb = rb*W+cb;
      bool yesno = red[ka] && red[kb] && graph.same(ka,kb);
      cout << (yesno ? "Yes" : "No") << endl;
    } else {
      assert(false);
    }
  }
  return 0;
}

