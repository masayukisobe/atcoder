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

const int inf = (1<<30);

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,M;
  cin >> N >> M;
  vector<ii> p;
  for (int i=0; i<N; i++) {
    int a,b; cin >> a >> b;
    p.emplace_back(a,b);
  }
  vector<ii> q;
  for (int i=0; i<M; i++) {
    int c,d; cin >> c >> d;
    q.emplace_back(c,d);
  }
  for (int i=0; i<N; i++) {
    int lmin = inf;
    auto [a,b] = p[i];
    int cp = 0;
    for (int j=0; j<M; j++) {
      auto [c,d] = q[j];
      int l = abs(a-c)+abs(b-d);
      if (l<lmin) {
        lmin = l;
        cp = j+1;
      }
    }
    assert(cp>0 && cp<=M);
    cout << cp << endl;
  }
  return 0;
}

