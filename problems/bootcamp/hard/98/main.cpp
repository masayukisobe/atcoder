// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W;
  cin >> H >> W;
  vi c(26);
  rep(i,H) {
    string s; cin >> s;
    rep(j,W) c[s[j]-'a']++;
  }
  int g1=0,g2=0;
  for (int n:c) {
    int d = n%4;
    if (d==1) g1++;
    if (d==2) g2++;
    if (d==3) g1++,g2++;
  }
  
  int h1=H%2, w1=W%2;
  if (h1 and w1) g1--;
  if (h1) g2-=W/2;
  if (w1) g2-=H/2;
  bool ans = g1<=0 and g2<=0;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}

