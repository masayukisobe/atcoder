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

void output(int x) {
  for (int n=100000; n>0; n/=10) {
    char c = '0'+(x/n)%10;
    cout << c;
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,M;
  cin >> N >> M;
  vector<int> v(N+1);
  priority_queue<iii> que;
  for (int i=1; i<=M; i++) {
    int p,y; cin >> p >> y;
    que.emplace(y,p,i);
    v[p]++;
  }
  vector<ii> c(M+1);
  while (!que.empty()) {
    auto [y,p,i] = que.top();
    que.pop();
    c[i].first = p;
    c[i].second = v[p];
    v[p]--;
  }
  for (int i=1; i<=M; i++) {
    output(c[i].first);
    output(c[i].second);
    cout << endl;
  }
  return 0;
}

