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

int fig[100];

void dfs(int d, int maxd, int& k, int pre) {
  if (d==maxd) {
    k--;
    if (k==0) {
      assert(d==maxd);
      for (int i=0; i<maxd; i++) {
        cout << fig[i];
      }
      cout << endl;
    }
    return;
  }
  for (int i=(d==0 ? 1 : 0); i<=9 && k>=0; i++) {
    if (d>0 && abs(pre-i)>=2) continue;
    fig[d] = i;
    dfs(d+1,maxd,k,i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int K;
  cin >> K;
  for (int d=1; d<100 && K>0; d++) {
    dfs(0,d,K,-1);
  }
  return 0;
}

