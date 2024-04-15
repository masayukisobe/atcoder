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
  
  int N,Q;
  cin >> N >> Q;
  vector<ll> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  vector<ll> gap(N);
  ll cost = 0;
  for (int i=1; i<N; i++) {
    gap[i] = a[i]-a[i-1];
    cost += abs(gap[i]);
  }
  for (int i=0; i<Q; i++) {
    int L,R;
    ll v;
    cin >> L >> R >> v;
    L--,R--;
    if (L>0) {
      ll g1=gap[L];
      ll g2=g1+v;
      cost += abs(g2)-abs(g1);
      gap[L] = g2;
    }
    if (R<N-1) {
      ll g1=gap[R+1];
      ll g2=g1-v;
      cost += abs(g2)-abs(g1);
      gap[R+1] = g2;
    }
    cout << cost << endl;
  }
  return 0;
}

