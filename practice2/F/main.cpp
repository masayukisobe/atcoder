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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N, M;
  cin >> N >> M;
  vector<mint> a(N);
  vector<mint> b(M);
  for (int i=0; i<N; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  for (int i=0; i<M; i++) {
    int x;
    cin >> x;
    b[i] = x;
  }
  auto c = convolution(a,b);
  for (int i=0; i< N + M - 1; i++) {
    if (i>0) cout << " ";
    cout << c[i].val();
  }
  cout << endl;
  return 0;
}

