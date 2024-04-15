// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
namespace {
using namespace std;
  //#pragma GCC diagnostic ignored "-Wunused-function"
  //n#include<atcoder/all>
  //#pragma GCC diagnostic warning "-Wunused-function"
  //using namespace atcoder;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll L,R;  
  cin >> L >> R;

  vector<pair<ll,ll>> ans;

  ll p=1,l=L,r=R;
  while(l<r) {
    if (l&p) {
      ans.emplace_back(l, l+p);
      l+=p;
    }
    if (r&p) {
      ans.emplace_back(r-p, r);
      r-=p;
    }
    p<<=1;
  }
  sort(ans.begin(),ans.end());
  cout << ans.size() << endl;
  for (auto& [x,y] : ans) {
    cout << x << " " << y << endl;
  }
  return 0;
}

