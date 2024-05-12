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
#define debug(x) cout << #x << ": " << x << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

int x[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int A,B;
  cin >> A >> B;
  int me = (A+B)%2;
  vi a(A+1),b(B+1);
  rep(i,A) cin >> a[A-i];
  rep(i,B) cin >> b[B-i];
  rep2e(i,1,A) {
    x[i][0] = x[i-1][0];
    if (i%2==me) x[i][0] += a[i];
  }
  rep2e(j,1,B) {
    x[0][j] = x[0][j-1];
    if (j%2==me) x[0][j] += b[j];
  }
  rep2e(i,1,A) {
    rep2e(j,1,B) {
      int turn = (i+j)%2;
      int take_a = x[i-1][j];
      int take_b = x[i][j-1];
      if (turn == me) {
        x[i][j] = max(a[i]+take_a,b[j]+take_b);
      } else {
        x[i][j] = min(take_a,take_b);
      }
    }
  }
  cout << x[A][B] << endl;
  return 0;
}

