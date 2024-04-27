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

#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<int> c1(N);
  vector<mint> c2(N);
  for (int i=0; i<N; i++) {
    int d; cin >> d;
    c1[i]=d;
    c2[d]++;
  }
  if (c1[0]!=0 || c2[0]!=1) {
    cout << 0 << endl;
    return 0;
  }
  mint ans = 1;
  for (int i=1; i<N; i++) {
    ans *= c2[c1[i]-1];
  }
  cout << ans.val() << endl;
  return 0;
}

