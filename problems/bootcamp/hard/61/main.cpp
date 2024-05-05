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
  int K;
  cin >> s >> K;
  for (int i=0; i<s.size(); i++) {
    int n = s[i]-'a';
    if (i==s.size()-1) {
      s[i] = char('a'+(n+K)%26);
    } else if (n>0 and K>=26-n) {
      K-=26-n;
      s[i] = 'a';
    }
  }
  cout << s << endl;
  return 0;
}

