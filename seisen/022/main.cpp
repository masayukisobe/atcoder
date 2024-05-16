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

double f(double x, double P) {
  return x+P/pow(2.0,x/1.5);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  double P;
  cin >> P;
  double lb=0, ub=1e10;
  while (ub-lb>0.0000000001) {
    double c = (ub-lb)/3;
    double a = lb+c;
    double b = ub-c;
    double fa = f(a,P);
    double fb = f(b,P);
    if (fa < fb) ub=b; else lb=a;
  }
  cout << fixed << setprecision(10) << f(ub,P) << endl;
  return 0;
}

