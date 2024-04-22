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
  
  ll a,b,x;
  cin >> a >> b >> x;
  ll ax = a==0 ? 0 : (a-1)/x+1;
  ll bx = b/x + 1;
  cout << bx-ax << endl;
  return 0;
}

