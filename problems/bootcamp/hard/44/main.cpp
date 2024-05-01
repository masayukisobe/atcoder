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

int npop(int mask) {
  int c=0;
  while (mask>0) {
    if (mask&1) c++;
    mask >>= 1;
  }
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<vector<ii>> xy(N);
  for (int i=0; i<N; i++) {
    int A;
    cin >> A;
    for (int j=0; j<A; j++) {
      int x,y;
      cin >> x >> y;
      xy[i].emplace_back(x-1,y);
    }
  }

  int ans = 0;
  for (int mask=0; mask<(1<<N); mask++) {
    bool ok = true;
    for (int i=0; i<N && ok; i++) {
      if ((mask&(1<<i))==0)
        continue;
      for (auto [x,y] :  xy[i]) {
        if (((mask>>x)&1)!=y) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      int c = npop(mask);
      ans = max(c,ans);
    }
  }
  cout << ans << endl;
  return 0;
}

