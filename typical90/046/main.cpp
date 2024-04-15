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
  
  int N;
  cin >> N;
  vector<ll> a(N),b(N),c(N);
  for (int i=0; i<N; i++) cin >> a[i];
  for (int i=0; i<N; i++) cin >> b[i];
  for (int i=0; i<N; i++) cin >> c[i];
  vector<ll> dp1(46);
  for (int i=0; i<N; i++) {
    dp1[a[i]%46]++;
  }
  vector<ll> dp2(46);
  for (int i=0; i<N; i++) {
    for (int j=0; j<46; j++) {
      dp2[(j+b[i])%46] += dp1[j];
    }
  }
  vector<ll> dp3(46);
  for (int i=0; i<N; i++) {
    for (int j=0; j<46; j++) {
      dp3[(j+c[i])%46] += dp2[j];
    }
  }
  cout << dp3[0] << endl;
  return 0;
}

