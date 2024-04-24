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
  
  string s;
  cin >> s;
  int ans = 1;
  for (int i=s.size()-3; i>=0; i-=2) {
    //debug(s.substr(0,i+1));
    bool ok = true;
    int m = (i+1)/2;
    //debug(m);
    for (int j=0; j<m; j++) {
      if (s[j]!=s[m+j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = i+1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}

