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

#define lb lower_bound
#define ub upper_bound

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ull N;
  cin >> N;
  ull n = 0;
  for (ull p=2; p*p<=N; p++) {
    if (N%p!=0) continue;
    while (N%p==0) {
      N/=p;
      n++;
    }
  }
  if (N!=1) n++;
  ull ans=0;
  while (n>1) {
    n=(n+1)/2;
    ans++;
  }
  cout << ans << endl;
  return 0;
}

