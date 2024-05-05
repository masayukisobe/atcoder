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

ll c[11][11];

void check(int n) {
  int first = n%10;
  int last = first;
  while (n>0) {
    last = n%10;
    n/=10;
  }
  c[first][last]++;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  for (int n=1; n<=N; n++) {
    check(n);
  }
  ll ans = 0;
  for (int i=0; i<=9; i++) {
    for (int j=0; j<=9; j++) {
      ans += c[i][j]*c[j][i];
    }
  }
  cout << ans << endl;
  return 0;
}

