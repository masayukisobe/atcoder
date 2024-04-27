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
  int ans = (1<<30);
  for (ll a=1; a*a<=N; a++) {
    if (N%a==0) {
      ll b = N/a;
      ll x = max(a,b);
      int n = 0;
      while (x>0) {
        n++;
        x/=10;
      }
      ans = min(n,ans);
    }
  }
  cout << ans << endl;
  return 0;
}

