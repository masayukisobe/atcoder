// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define lb lower_bound
#define ub upper_bound

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

//#include <atcoder/all>
#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

mint total(mint a, mint b) {
  return (a+b)*(b-a+1)/2;
}

mint count(ull N) {
  mint r=0;
  for (ull i=0,p=1; p<=N && i<=18; i++,p*=10) {
    r += mint(i+1)*total(p,min(N,p*10-1));
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ull L,R;
  cin >> L >> R;
  mint c = count(R)-count(L-1);
  cout << c.val() << endl;
  return 0;
}

