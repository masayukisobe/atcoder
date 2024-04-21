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
  
  ll N, Q;
  cin >> N >> Q;
  ll xmin, xmax;
  ll ymin, ymax;
  vector<ll> xx(N);
  vector<ll> yy(N);
  for (ll i=0; i<N; i++) {
    ll x, y;
    cin >> x >> y;
    xmin = min(x,xmin);
    xmax = max(x,xmax);
    ymin = min(y,ymin);
    ymax = max(y,ymax);
    xx[i] = x, yy[i] = y;
  }
  vector<ll> quadrant_best(4,-1);
  for (ll q=0; q<4; q++) {
    ll best = -1;
    for (ll i=0; i<N; i++) {
      ll d;
      switch(q) {
      case 0:
        d = abs(xx[i]-xmin)+abs(yy[i]-ymin);
        break;
      case 1:
        d = abs(xx[i]-xmax)+abs(yy[i]-ymin);
        break;
      case 2:
        d = abs(xx[i]-xmax)+abs(yy[i]-ymax);
        break;
      case 3:
        d = abs(xx[i]-xmin)+abs(yy[i]-ymax);
        break;
      }
      if (d>best) {
        best = d;
        quadrant_best[q] = i;
      }
    }
  }
  for (ll q=0; q<4; q++) {
    assert(quadrant_best[q]>=0);
  }
  
  for (ll i=0; i<Q; i++) {
    ll j;
    cin >> j; j--;
    ll best = 0;
    for (ll q=0; q<4; q++) {
      ll k = quadrant_best[q];
      ll d = abs(xx[j]-xx[k]) + abs(yy[j]-yy[k]);
      best = max(d, best);
    }
    cout << best << endl;
  }
  return 0;
}

