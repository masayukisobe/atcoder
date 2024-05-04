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
  
  int N,X,Y,Z;
  cin >> N >> X >> Y >> Z;
  bool ans;
  if (X>=Y) {
    ans = (X>=Z && Z>=Y);
  } else {
    ans = (X<=Z && Z<=Y);
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}

