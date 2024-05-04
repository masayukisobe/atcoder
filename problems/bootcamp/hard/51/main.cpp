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

#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int X,Y;
  cin >> X >> Y;
  if ((X+Y)%3!=0 or 2*X<Y or 2*Y<X) {
    cout << 0 << endl;
    return 0;
  }

  // calc n,m of nCm
  int n = (X+Y)/3;
  int diff = abs(X-Y);
  int m;
  if (n%2==0) {
    m = n/2-diff/2;
  } else {
    m = (n-1)/2-diff/2;
  }

  mint nCm=1;
  for (int i=1,j=n; i<=m; i++,j--) {
    nCm *= j;
    nCm /= i;
  }
  
  cout << nCm.val() << endl;
  return 0;
}

