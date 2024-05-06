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
ull X;

ull burgur[60];
ull patty[60];

ull dfs(int n) {
  if (X==0) return 0LL;
  ull ret=0LL;
  if (burgur[n]<=X) {
    X-=burgur[n];
    ret+=patty[n];
  } else if (n>0) {
    if (X>0) X--;
    ret += dfs(n-1);
    if (X>0) X--,ret++;
    ret += dfs(n-1);
    if (X>0) X--;
  } else {
    assert(false);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> N >> X;
  burgur[0] = 1;
  patty[0] = 1;
  for (int i=1; i<=N; i++) {
    burgur[i] = 2*burgur[i-1]+3;
    patty[i] = 2*patty[i-1]+1;
  }
  cout << dfs(N) << endl;
  return 0;
}

