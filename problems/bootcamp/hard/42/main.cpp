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
  
  int N;
  string s;
  cin >> N >> s;
  int max_neg = 0;
  int d = 0;
  for (int i=0; i<N; i++) {
    if (s[i]=='(') d++;
    if (s[i]==')') d--;
    max_neg = max(max_neg,-d);
  }
  int max_posi = d+max_neg;
  for (int i=0; i<max_neg; i++) cout << '(';
  cout << s;
  for (int i=0; i<max_posi; i++) cout << ')';
  cout << endl;
  return 0;
}

