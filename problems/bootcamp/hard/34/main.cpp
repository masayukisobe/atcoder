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
  vector<int> c(N);
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    c[a]++;
  }
  mint ans = 1;
  for (int n=N-1; n>=0; n-=2) {
    if (n==0) {
      if (c[n]!=1) {
        ans=0; break;
      }
    } else {
      if (c[n]!=2) {
        ans=0; break;
      }
      ans*=2;
    }
  }
  cout << ans.val() << endl;
  return 0;
}

