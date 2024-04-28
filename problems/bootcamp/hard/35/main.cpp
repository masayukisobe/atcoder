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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,H;
  cin >> N >> H;
  priority_queue<pair<int,bool>> que;
  for (int i=0; i<N; i++) {
    int a,b; cin >> a >> b;
    que.emplace(a,true);
    que.emplace(b,false);
  }
  ll ans = 0;
  int h = H;
  while (h>0) {
    assert(!que.empty());
    auto [x,reuse] = que.top();
    que.pop();
    if (!reuse) {
      ans++;
      h -= x;
      continue;
    }
    int n = h/x;
    ans += n;
    h -= x*n;
    if (h>0) {
      ans++;
      h = 0;
    }
    break;
  }
  cout << ans << endl;
  return 0;
}

