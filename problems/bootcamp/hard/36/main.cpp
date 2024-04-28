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

  const ll t = 1000LL*1000LL*1000LL;
  
  ll S;
  cin >> S;
  ll x = t-S%t;
  if (x>=t) x%=t;
  ll y = (S+x)/t;
  cout << "0 0 1000000000 1 " << x << " " << y << endl;
  return 0;
}

