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

using line_t = pair<ii,ii>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  if (N==1) {
    cout << 1 << endl;
    return 0;
  }
  
  vector<ii> xy;
  for (int i=0; i<N; i++) {
    int x,y; cin >> x >> y;
    xy.emplace_back(x,y);
  }
  sort(xy.begin(),xy.end());
  
  vector<ii> pq;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (i==j) continue;
      auto [xi,yi] = xy[i];
      auto [xj,yj] = xy[j];
      int p = xj-xi;
      int q = yj-yi;
      if (p!=0 or q!=0) {
        pq.emplace_back(p,q);
      }
    }
  }
  sort(pq.begin(),pq.end());
  pq.erase(unique(pq.begin(),pq.end()), pq.end());

  int ans = (1<<30);
  vector<line_t> lines;
  for (auto [p,q] : pq) {
    //cout << p << " " << q << endl;
    lines.clear();
    for (auto [x,y] : xy) {
      bool done = false;
      for (auto &line: lines) {
        auto [ax,ay] = line.first;
        auto [bx,by] = line.second;
        if (x+p==ax and y+q==ay) {
          line.first = ii(x,y);
          done = true;
          break;
        }
        if (x-p==bx and y-q==by) {
          line.second = ii(x,y);
          done = true;
          break;
        }
      }
      if (!done) {
        lines.emplace_back(ii(x,y),ii(x,y));
      }
    }
    ans = min(ans,int(lines.size()));
  }
  cout << ans << endl;
  return 0;
}

