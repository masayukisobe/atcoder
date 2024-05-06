// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  string s1,s2;
  cin >> N >> s1 >> s2;
  vector<bool> bar;
  rep(i,N) {
    if (s1[i]==s2[i])
      bar.push_back(true);
    else {
      bar.push_back(false);
      i++;
    }
  }
  const int M = bar.size();
  mint ans = 1;
  if (bar[0]) {
    ans *= 3;
  } else {
    ans *= 6;
  }
  rep2(i,1,M) {
    bool pre=bar[i-1],now=bar[i];
    //debug(i); debug(pre); debug(now);
    if (pre && now) { // ||
      ans *= 2;
      continue;
    }
    if (pre && !now) { // |=
      ans *= 2;
      continue;
    }
    if (!pre && now) { // =|
      ans *= 1;
      continue;
    }
    if (!pre && !now) { // ==
      ans *= 3;
      continue;
    }
    assert(false);
  }
  cout << ans.val() << endl;
  return 0;
}

