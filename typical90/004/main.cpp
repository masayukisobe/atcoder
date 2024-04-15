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

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W;
  cin >> H >> W;
  vector<vector<ll>> a(H+1,vector<ll>(W+1));
  vector<ll> x(W+1);
  vector<ll> y(H+1);
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      cin >> a[i][j];
      x[j] += a[i][j];
      y[i] += a[i][j];
    }
  }
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      if (j>1) cout << " ";
      cout << x[j]+y[i]-a[i][j];
    }
    cout << endl;
  }
  return 0;
}

