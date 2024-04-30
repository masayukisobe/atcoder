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
  
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A.begin(),A.end());
  ll ans = 0;
  int pre=0,n=0;
  for (int i=0; i<N; i++) {
    if (pre==A[i]) n^=1;
    else {
      ans += n;
      n = 1;
    }
    pre = A[i];
  }
  ans += n;
  cout << ans << endl;
  return 0;
}

