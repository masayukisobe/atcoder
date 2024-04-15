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

#include <atcoder/all>
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<ull> a(N);
  vector<ull> b(N);
  for (int i=0; i<N; i++) cin >> a[i];
  for (int i=0; i<N; i++) cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ull ans=0;
  for (int i=0; i<N; i++) {
    int x=a[i];
    int y=b[i];
    ans += max(x,y)-min(x,y);
  }
  cout << ans << endl;
  return 0;
}

