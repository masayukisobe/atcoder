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
  
  int N,M;
  cin >> N >> M;
  priority_queue<int> que;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    que.push(a);
  }
  for (int i=0; i<M; i++) {
    int b = que.top()/2;
    que.pop();
    que.push(b);
  }
  ll ans = 0;
  while (!que.empty()) {
    ans += que.top();
    que.pop();
  }
  
  cout << ans << endl;
  return 0;
}

