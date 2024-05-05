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
  ull R = min(1000000ULL,N);
  ull ans = 0;
  for (ull r=1; r<=R; r++) {
    ull m = (N-r)/r;
    if (m>0 and N%m==N/m) ans += m;
  }
  cout << ans << endl;
  return 0;
}

