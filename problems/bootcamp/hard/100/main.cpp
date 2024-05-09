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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  string first;
  {
    cout << 0 << endl;
    cin >> first;
    if (first=="Vacant") return 0;
  }

  int lb=0,ub=N;
  while (ub-lb>1) {
    int k = (ub+lb)/2;
    cout << k << endl;
    string ans; cin >> ans;
    if (ans=="Vacant") return 0;
    if ((k-lb)%2==0) {
      if (first==ans) {
        lb=k;
        first=ans;
      } else {
        ub=k;
      }
    } else {
      if (first!=ans) {
        lb=k;
        first=ans;
      } else {
        ub=k;
      }
    }
  }
  return 0;
}

