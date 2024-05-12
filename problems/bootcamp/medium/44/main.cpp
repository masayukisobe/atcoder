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
#define _(x) #x << "=" << x << " "
#define debug(x) cout << _(x) << endl
#define debug2(x,y) cout << _(x) << _(y) << endl
#define debug3(x,y,z) cout << _(x) << _(y) << _(z) << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

void show(vi v) {
  for (auto x:v) cout << x << " ";
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  cin >> n;
  vvi v(2);
  rep(i,n) {
    int a; cin >> a;
    v[i%2].push_back(a);
  }
  if (n%2) swap(v[0],v[1]);
  reverse(v[1].begin(),v[1].end());
  show(v[1]);
  show(v[0]);
  cout << endl;
  return 0;
}

