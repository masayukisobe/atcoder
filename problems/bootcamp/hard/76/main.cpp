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
  int N = s.size();

  auto num = [&](int i, int j) -> ll {
    ll n=0;
    for (int k=i; k<j; k++) {
      n = 10*n + (s[k]-'0');
    }
    return n;
  };
    
  ll ans = 0;
  for (int mask=0; mask<(1<<(N-1)); mask++) {
    int m = mask, i=0, j=1;
    while (m>0) {
      if (m&1) {
        //debug(num(i,j));
        ans += num(i,j);
        i = j;
      }
      j++;
      m>>=1;
    }
    //debug(num(i,N));
    ans += num(i,N);
  }
  cout << ans << endl;
  return 0;
}

