// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int ans[4] = {6,2,4,8};
  
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    ll n,m,k;
    cin >> n >> m >> k;
    ll n1;
    if (n<m) {
      n1 = n;
    } else { // n>=m
      ll d = (n-m)/(m-k);
      n1 = n-d*(m-k);
      while (n1>=m) n1 -= m-k;
    }
    if (n1==m-1 && k==m-1) {
      cout << 0 << endl;
    } else {
      cout << ans[n1%4] << endl;
    }
  }
  return 0;
}

