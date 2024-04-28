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

void swap(int& x, int& y) {
  int z = x;
  x = y;
  y = z;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string s,t;
  cin >> s >> t;
  vector f(26,-1),g(26,-1);
  bool possible = true;
  for (int i=0; i<s.size(); i++) {
    int a = s[i]-'a';
    int b = t[i]-'a';
    if (f[a]>=0 && f[a]!=b || g[b]>=0 && g[b]!=a) {
      possible = false;
      break;
    }
    f[a] = b;
    g[b] = a;
  }
  cout << (possible ? "Yes" : "No") << endl;
  return 0;
}

