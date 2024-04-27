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
  cin >> N;
  ll ans=0;
  int a1=0;
  int b0=0;
  int ab=0;
  for (int i=0; i<N; i++) {
    string s; cin>>s;
    int M = s.size();
    for (int j=1; j<M; j++) {
      if (s[j]=='B' && s[j-1]=='A') ans++;
    }
    if (s[0]=='B' && s[M-1]=='A') ab++;
    else {
      if (s[0]=='B') b0++;
      if (s[M-1]=='A') a1++;
    }
  }
  //debug(b0);debug(a1);debug(ab);
  if (ab>0) {
    ans += ab-1;
    if (a1>0) {
      ans++;
      a1--;
    }
    if (b0>0) {
      ans++;
      b0--;
    }
  }
  ans += min(a1,b0);
  cout << ans << endl;
  return 0;
}

