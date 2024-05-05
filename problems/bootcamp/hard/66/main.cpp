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
  int a=0;
  for (int i=0; i+3<=s.size(); i++) {
    char x = s[i];
    char y = s[i+1];
    char z = s[i+2];
    if (x=='A') a++; else a=0;
    if (x=='A' and y=='B' and z=='C') {
      ans += a;
      s[i+2] = 'A';
      a--;
      i++;
    } 
  }
  cout << ans << endl;
  return 0;
}

