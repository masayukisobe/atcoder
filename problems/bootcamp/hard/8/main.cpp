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
  
  ull N;
  cin >> N;
  if (N%2==1) {
    cout << 0 << endl;
  } else {
    ll ans = 0;
    N /= 10ULL;
    ans += N;
    while (N>0) {
      N /= 5;
      ans += N;
    }
    cout << ans << endl;
  }
  return 0;
}

