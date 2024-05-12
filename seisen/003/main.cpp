// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define endl '\n'
#define _(x) #x << "=" << x << " "
#define debug(x) cout << _(x) << endl
#define debug2(x,y) cout << _(x) << _(y) << endl
#define debug3(x,y,z) cout << _(x) << _(y) << _(z) << endl
#define popcount __builtin_popcount
#define INF INT_MAX
#define LL_INF LLONG_MAX
#define rep(a,b) for (int a=0; a<(b); a++)
#define rep2(a,b,c) for (int a=(b); a<(c); a++)
#define rep2e(a,b,c) for (int a=(b); a<=(c); a++)
#define rep2d(a,b,c) for (int a=(b); a>=(c); a--)

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  vector<bool> check(26);
  check['A'-'A']=true;
  check['C'-'A']=true;
  check['G'-'A']=true;
  check['T'-'A']=true;

  string s;
  cin >> s;
  const int N=s.size();
  rep2d(l,N,1) {
    rep2e(i,0,N-l) {
      bool ok = true;
      rep(j,l) {
        if (!check[s[i+j]-'A']) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << l << endl;
        return 0;
      }
    }
  }
  cout << 0 << endl;
  return 0;
}

