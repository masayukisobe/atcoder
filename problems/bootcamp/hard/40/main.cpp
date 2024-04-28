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
  int i=0;
  int j=s.size()-1;
  int cost = 0;
  while (i<=j) {
    if (s[i]==s[j]) {
      i++; j--;
      continue;
    }
    if (s[i]=='x') {
      cost++; i++;
      continue;
    }
    if (s[j]=='x') {
      cost++; j--;
      continue;
    }
    break;
  }
  cout << (i<=j ? -1 : cost) << endl;
  return 0;
}

