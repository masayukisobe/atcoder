// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;

bool vis[8][100001];
mint memo[8][100001];

const string t("atcoder");
const int M = t.size(); // =7:

// check t[i] <--> s[j]
mint dfs(int i, int j, string& s, int N) {
  if (i==M) return 1;
  if (j==N) return 0;
  //cout << i << ":" << t.substr(i) << " ; " << j << ":" << s.substr(j) << endl;
  if (vis[i][j]) return memo[i][j];
  mint r = 0;
  if (N-j > M-i) { // skip
    r += dfs(i,j+1,s,N);
  }
  if (t[i]==s[j]) { // hit
    r += dfs(i+1,j+1,s,N);
  }
  vis[i][j] = true;
  memo[i][j] = r;
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  string s;
  cin >> N >> s;
  assert(N==s.size());
  mint r = dfs(0,0,s,N);
  cout << r.val() << endl;
  return 0;
}

