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
  ll ans = 0;
  ll b = 0;
  for (int i=0; i<s.size(); i++) {
    if (s[i]=='B') b++;
    else if (s[i]=='W') ans += b;
  }
  cout << ans << endl;
  return 0;
}

