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
  
  int N,M;
  cin >> N >> M;
  vector<int> v(N+1);
  for (int i=0; i<M; i++) {
    int a,b;
    cin >> a >> b;
    if (a>b) {
      v[a]++;
    } else if (b>a) {
      v[b]++;
    }
  }
  int ans=0;
  for (int i=1; i<=N; i++) {
    if (v[i]==1) ans++;
  }
  cout << ans << endl;
  return 0;
}

