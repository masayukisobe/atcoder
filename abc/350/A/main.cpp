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

bool check(string& s) {
  assert(s.size()==6);
  if (s[0]!='A') return false;
  if (s[1]!='B') return false;
  if (s[2]!='C') return false;
  int a = s[3]-'0';
  int b = s[4]-'0';
  int c = s[5]-'0';
  if (a<0 || a>9) return false;
  if (b<0 || b>9) return false;
  if (c<0 || c>9) return false;
  int n = 100*a+10*b+c;
  return (n>=1 && n<350 && n!=316);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  string s;
  cin >> s;
  cout << (check(s) ? "Yes" : "No") << endl;
  return 0;
}

