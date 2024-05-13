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

double dist(ii& a, ii& b) {
  double x1 = a.first;
  double y1 = a.second;
  double x2 = b.first;
  double y2 = b.second;
  double dx=x2-x1;
  double dy=y2-y1;
  return sqrt(dx*dx+dy*dy);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<ii> v;
  v.reserve(N);
  rep(i,N) {
    int x,y; cin >> x >> y;
    v.emplace_back(x,y);
  }
  
  vi p(N);
  iota(p.begin(),p.end(),0);
  
  double num=0;
  double total=0;
  do {
    num += 1.0;
    rep(i,N-1) total+=dist(v[p[i]],v[p[i+1]]);
  } while (next_permutation(p.begin(),p.end()));
  cout << fixed << setprecision(10) << total / num << endl;
  return 0;
}

