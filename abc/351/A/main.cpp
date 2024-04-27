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
  
  ll a=0,b=0;
  for (int i=0; i<9; i++) {
    ll x; cin >> x;
    a += x;
  }
  for (int i=0; i<8; i++) {
    ll x; cin >> x;
    b += x;
  }
  cout << max(a-b+1,0LL) << endl;
  return 0;
}

