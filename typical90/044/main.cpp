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
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  int offset = 0;
  for (int i=0; i<Q; i++) {
    int t,x,y;
    cin >> t >> x >> y;
    x--,y--;
    if (t==1) {
      x = (N+x-offset)%N;
      y = (N+y-offset)%N;
      int b = a[x];
      a[x] = a[y];
      a[y] = b;
    } else if (t==2) {
      offset = (offset+1)%N;
    } else if (t==3) {
      x = (N+x-offset)%N;
      cout << a[x] << endl;
    } else {
      assert(false);
    }
  }
  return 0;
}

