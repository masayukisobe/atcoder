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
  
  string s,t;
  cin >> s;
  cin >> t;
  int i=0;
  for (int j=0; j<t.size(); j++) {
    if (s[i]==t[j]) {
      if (i>0) cout << " ";
      cout << (j+1);
      i++;
    }
  }
  cout << endl;
  assert(i==s.size());
  return 0;
}

