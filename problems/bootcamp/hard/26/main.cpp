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
  
  int K,T;
  cin >> K >> T;
  priority_queue<int> que;
  for (int i=0; i<T; i++) {
    int a; cin >> a;
    que.push(a);
  }
  while (que.size()>=2) {
    int a = que.top();
    que.pop();
    int b = que.top();
    que.pop();
    if (a>b) que.push(a-b);
  }
  int ans = 0;
  if (que.size()>0) ans += que.top()-1;
  cout << ans << endl;
  return 0;
}

