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

int N;
char s[11];

void dfs(int i, int jmax) {
  if (i==N) {
    cout << s << endl;
    return;
  }
  for (int j=0; j<=jmax+1; j++) {
    s[i] = 'a'+j;
    dfs(i+1,max(j,jmax));
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> N;
  dfs(0,-1);
  return 0;
}

