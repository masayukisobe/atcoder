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

const int Z=1000001LL;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int M;
  cin >> M;
  vll X(M),Y(M);
  rep(i,M) cin>>X[i]>>Y[i];
  
  int N;
  cin >> N;
  vll P(N),Q(N);
  unordered_set<ll> us;
  rep(i,N) {
    cin>>P[i]>>Q[i];
    us.insert(P[i]*Z+Q[i]);
  }

  rep2(i,1,M) {
    X[i] -= X[0];
    Y[i] -= Y[0];
  }
  rep(i,N) {
    ll p=P[i],q=Q[i];
    bool ok=true;
    rep2(j,1,M) {
      ll x=p+X[j],y=q+Y[j];
      if (!us.contains(x*Z+y)) {
        ok=false; break;
      }
    }
    if (ok) {
      cout << P[i]-X[0] << " " << Q[i]-Y[0] << endl;
      return 0;
    }
  }
  
  return 0;
}

