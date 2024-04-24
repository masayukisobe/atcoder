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

int ns;
int nt;
char s[60];
char t[60];
char w[60];

bool dfs(int i, int j) {
  if (i==ns) {
    if (j==nt) {
      w[ns]=0; // null charactor
      return true;
    }
    return false;
  }
  if (s[i]=='?') {
    if (j==0 || j==nt) {
      w[i] = 'a';
      if (dfs(i+1,j)) return true;
    }
    if (j<nt) {
      w[i] = t[j];
      if (dfs(i+1,j+1)) return true;
    }
  } else {
    if (j==0 || j==nt) {
      w[i] = s[i];
      if (dfs(i+1,j)) return true;
    }
    if (j<nt && s[i]==t[j]) {
      if (dfs(i+1,j+1)) return true;
    }
  }
  return false;
}


int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string S,T;
  cin >> S;
  cin >> T;
  ns = S.size();
  nt = T.size();
  //debug(ns); debug(nt);
  for (int i=0; i<ns; i++) s[i]=S[i];
  for (int i=0; i<nt; i++) t[i]=T[i];
  if (dfs(0,0)) {
    cout << w << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}

