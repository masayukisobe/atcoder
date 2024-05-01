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
  int c=0;
  int ans = s.size();
  for (int i=0; i<s.size(); i++) {
    if (s[i]=='S') c++;
    else if (s[i]=='T') {
      if (c>0) {
        c--; ans -= 2;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

