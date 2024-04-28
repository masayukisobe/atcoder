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

using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<int> c(N+1);
  vector<int> pp;
  for (int i=2; i<=N; i++) {
    if (c[i]==0) {
      pp.push_back(i);
    }
    for (int j=i; j<=N; j+=i) c[j]++;
  }
  mint ans = 1;
  for (auto p : pp) {
    mint t = 1;
    for (int i=2; i<=N; i++) {
      int k = i;
      while (k%p==0) {
        k/=p;
        t++;
      }
    }
    //debug(p); debug(t.val());
    ans *= t;
  }
  cout << ans.val() << endl;
  return 0;
}

