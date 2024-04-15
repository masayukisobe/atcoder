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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  const double PI2 = M_PI*2;
  const double _360 = 360;

  int T,L,X,Y;
  cin >> T >> L >> X >> Y;
  double t = (double)(T);
  double l2 = (double)(L)/2;
  double x = (double)(X);
  double y = (double)(Y);
  double z = 0;
  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int E;
    cin >> E;
    double e = (double)(E);
    double theta = PI2*e/t;
    double x1 = 0;
    double y1 = -l2*sin(theta);
    double z1 = l2-l2*cos(theta);
    double dx = x-x1;
    double dy = y-y1;
    double dz = z-z1;
    double arg = atan2(abs(dz),sqrt(dx*dx+dy*dy));
    cout << fixed << setprecision(10) << _360*arg/PI2 << endl;
  }
  return 0;
}

