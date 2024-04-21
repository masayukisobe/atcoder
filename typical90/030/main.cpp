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

  int N,K;
  cin >> N >> K;

  ll ans = 0;
  vector<int> count(N+1);
  for (int p=2; p<=N; p++) {
    if (count[p]>0) continue;
    for (int n=p; n<=N; n+=p) {
      count[n]++;
      if (count[n]==K) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

