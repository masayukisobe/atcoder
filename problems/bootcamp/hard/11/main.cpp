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
  
  ll A,B;
  cin >> A >> B;
  ll a = max(A,B);
  ll b = min(A,B);
  while (b>0) {
    ll r = a%b;
    a = b;
    b = r;
  }
  ll ans = 1;
  ll c = a;
  for (ll p=2; p*p<=a && p<=c; p++) {
    if (c%p==0) {
      ans++;
      c/=p;
    }
    while (c%p==0) c/=p;
  }
  if (c>1) ans++;
  cout << ans << endl;
  return 0;
}

