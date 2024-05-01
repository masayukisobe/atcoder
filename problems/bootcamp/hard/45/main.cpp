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

  vector<bool> prime(100001,true);

  prime[0] = false;
  prime[1] = false;
  for (int p=2; p<=100000; p++) {
    if (!prime[p]) continue;
    for (int q = p+p; q<=100000; q+=p) {
      prime[q] = false;
    }
  }
  vector<int> dp(100001);
  for (int i=3; i<100000; i+=2) {
    dp[i] = dp[i-2];
    if (prime[i] && prime[(i+1)/2]) {
      //if (i<100)  cout << i << endl;
      dp[i]++;
    }
  }
  
  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int l,r; cin >> l >> r;
    int n = dp[r];
    if (l>=3) n -= dp[l-2];
    cout << n << endl;
  }
  return 0;
}

