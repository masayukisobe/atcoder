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

const ll inf = (1LL<<30);

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  ll P;
  cin >> N >> P >> K;
  vector<ll> a(N*N);
  vector<ll> b;
  for (int i=0; i<N*N; i++) {
    cin >> a[i];
    if (a[i]<0) b.push_back(i);
  }

  vector<ll> d(N*N);

  auto count =
    [&](ll x) -> int {
      for (int i:b) a[i]=x;
      for (int i=0; i<N*N; i++) d[i]=a[i];
      for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
          for (int j=0; j<N; j++) {
            d[i*N+j] = min(d[i*N+j], d[i*N+k]+d[k*N+j]);
          }
        }
      }
      int n=0;
      for (int i=0; i<N; i++)
        for (int j=i+1; j<N; j++)
          if (d[i*N+j]<=P) n++;
      return n;
    };
  {
    int n = count(inf);
    if (n>K) {
      cout << 0 << endl;
      return 0;
    }
    if (n==K) {
      cout << "Infinity" << endl;
      return 0;
    }
  }
  ll lb,ub;
  lb = 0;
  ub = inf;
  while (ub-lb>1) {
    ll x = (lb+ub)/2;
    int n = count(x);
    //debug(lb); debug(ub); debug(x); debug(n);
    if (n>K)
      lb = x;
    else
      ub = x;
  }
  assert(ub-lb==1);
  ll x1 = ub;
  lb = x1-1;
  ub = inf;
  while (ub-lb>1) {
    ll x = (lb+ub)/2;
    int n = count(x);
    //debug(lb); debug(ub); debug(x); debug(n);
    if (n>=K)
      lb = x;
    else
      ub = x;
  }
  assert(ub-lb==1);
  ll x2 = ub;
  cout << x2-x1 << endl;
  return 0;
}

