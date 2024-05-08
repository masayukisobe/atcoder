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
  
  int N,K;
  cin >> N >> K;
  unordered_map<int,int> us;
  rep(i,N) {
    int a; cin >> a;
    if (!us.contains(a)) us[a]=0;
    us[a]++;
  }
  vi v;
  for (auto [_,x] : us) {
    v.push_back(x);
  }
  sort(v.begin(),v.end());

  int ans=0;
  int m = v.size();
  for (auto& x : v) {
    if (m<=K) break;
    ans += x;
    m--;
  }
  cout << ans << endl;
  return 0;
}

