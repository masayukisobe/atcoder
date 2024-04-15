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
  
  int N,K;
  cin >> N >> K;
  vector<pair<ll,int>> a(N),b(N);
  for (int i=0; i<N; i++) {
    ll x,y;
    cin >> x >> y;
    a[i] = {y,i};
    b[i] = {x-y,i};
  }
  make_heap(a.begin(),a.end());
  ll ans = 0;
  for (int i=0; i<K; i++) {
    auto [v,j] = a[0];
    // cout << j << " " << v << endl;
    pop_heap(a.begin(),a.end());
    a.pop_back();
    ans += v;
    a.push_back(b[j]);
    b[j] = {0,j};
    push_heap(a.begin(),a.end());
  }
  cout << ans << endl;
  return 0;
}

