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
  
  int H,W,A,B;
  cin >> H >> W >> A >> B;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cout << int(i<B ^ j<A);
    }
    cout << endl;
  }
  return 0;
}

