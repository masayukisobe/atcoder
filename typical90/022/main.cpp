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
//using namespace atcoder;

ull gcd(ull x, ull y) {
  if (x<y) {
    ull t = x;
    x = y;
    y = t;
  }
  while (y!=0) {
    ull t = x%y;
    x = y;
    y = t;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ull A,B,C;
  cin >> A >> B >> C;
  ull D = gcd(gcd(A,B),C);
  ull S = 0;
  S += A/D-1;
  S += B/D-1;
  S += C/D-1;
  cout << S <<endl;
  return 0;
}

