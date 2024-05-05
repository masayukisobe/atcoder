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

ll N;

ll dfs(ll n, ll k, int mask) {
  if (n>N) return 0;
  ll ret = 0;
  if (mask==7) ret++;
  ret += dfs(n+k*7,k*10,mask|4);
  ret += dfs(n+k*5,k*10,mask|2);
  ret += dfs(n+k*3,k*10,mask|1);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> N;
  cout << dfs(0,1,0) << endl;
  return 0;
}

