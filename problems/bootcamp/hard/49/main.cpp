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
  
  ll n,a,b;
  cin >> n >> a >> b;

  // calc x = (1+1)^2 - 1
  mint x = 1;
  mint i=2;
  ll m=n;
  while (m>0) {
    if (m&1) x*=i;
    i*=i;
    m>>=1;
  }
  x--;
  //cout << x.val() << endl;

  mint nCa = 1;
  for (ll i=1,j=n; i<=a; i++,j--) {
    nCa *= j;
    nCa /= i;
  }
  //cout << nCa.val() << endl;
  
  mint nCb = 1;
  for (ll i=1,j=n; i<=b; i++,j--) {
    nCb *= j;
    nCb /= i;
  }
  //cout << nCb.val() << endl;
  
  x -= nCa;
  x -= nCb;
  
  cout << x.val() << endl;
  return 0;
}

