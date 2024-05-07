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
#define debug(x) cout << #x << ": " << x << endl
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

  int N,M;
  cin >> N >> M;
  vi v(N);
  rep(i,M) {
    int a,b; cin >>a>>b; a--,b--;
    v[a]++; v[b]++;
  }
  // path (a,b) can be decomposed to (root,a),(root,b)
  // so count times that each vetex refered, then check it even or not.
  bool ans = all_of(v.begin(),v.end(),[](int x){return x%2==0;});
  
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}

