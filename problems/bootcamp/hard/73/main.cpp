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
  
  int N;
  cin >> N;
  
  vector<int> one;
  one.push_back(1);
  for (int i=6; i<=N; i*=6) one.push_back(i);
  for (int i=9; i<=N; i*=9) one.push_back(i);

  vector<int> wd(N+1);
  vector<vector<int>> v(2);
  v[0].push_back(0);
  for (int d=1; wd[N]==0; d++) {
    auto& now = v[d%2];
    now.clear();
    auto& pre = v[(d-1)%2];
    for (auto p : pre) {
      for (auto x : one) {
        if (p+x<=N and wd[p+x]==0) {
          wd[p+x] = d;
          now.push_back(p+x);
        }
      }
    }
  }
  cout << wd[N] << endl;
  return 0;
}

