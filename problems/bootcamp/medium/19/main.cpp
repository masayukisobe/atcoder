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
  
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  ull ans = 0;
  for (int r=0; r<=N; r+=R) {
    for (int g=0; g+r<=N; g+=G) {
      int b = N - (r+g);
      if (b%B==0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

