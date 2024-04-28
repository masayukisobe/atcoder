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
  vector<ii> v;
  for (int i=0; i<N; i++) {
    int x,l; cin >> x >> l;
    v.emplace_back(x+l,x-l);
  }
  sort(v.begin(),v.end());
  int rmax = -(1<<30);
  int ans = 0;
  for (auto [right,left] : v) {
    if (rmax<=left) {
      rmax = right;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

