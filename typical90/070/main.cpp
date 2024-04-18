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

//#include <atcoder/all>
//using namespace atcoder;

const ll inf = (1LL<<60);

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<ll> xx(N);
  vector<ll> yy(N);
  for (int i=0; i<N; i++) {
    cin >> xx[i] >> yy[i];
  }
  sort(xx.begin(), xx.end());
  sort(yy.begin(), yy.end());
  ll d1 = inf;
  for (int i=(N-1)/2; i<=N/2; i++) {
    ll x = xx[i], d = 0;
    for (ll x1 : xx) d += abs(x-x1);
    d1 = min(d,d1);
  }
  ll d2 = inf;
  for (int i=(N-1)/2; i<=N/2; i++) {
    ll y = yy[i], d = 0;
    for (ll y1 : yy) d += abs(y-y1);
    d2 = min(d,d2);
  }
  cout << d1+d2 << endl;
  return 0;
}

