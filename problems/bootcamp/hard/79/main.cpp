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
  
  int N,K;
  string s;
  cin >> N >> K >> s;
  vector<int> cp;
  cp.push_back(0);
  for (int i=1; i<N; i++) {
    if (s[i]!=s[i-1]) cp.push_back(i);
  }
  cp.push_back(N);
  //for (auto x : cp) debug(x);
  
  int ans = 0;
  int M = cp.size();
  for (int i=0; i<M-1; i++) {
    int l = cp[i];
    int r;
    if (s[l]=='0') {
      r = cp[min(i+2*K,M-1)];
    } else {
      r = cp[min(i+1+2*K,M-1)];
    }
    //debug(i); debug(l); debug(r);
    ans = max(ans,r-l);
  }
  cout << ans << endl;
  return 0;
}

