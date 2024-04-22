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

double expected(int l1,int r1,int l2,int r2) {
  int n1 = r1-l1+1;
  int n2 = r2-l2+1;
  int c = 0;
  r2 = min(r1,r2);
  l1 = max(l1,l2);
  for (int i=l1; i<=r1; i++) {
    for (int j=l2; j<=r2; j++) {
      if (i>j) c++;
    }
  }
  return ((double)c)/((double)(n1*n2));
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<ii> lr;
  for (int i=0; i<N; i++) {
    int l,r;
    cin >> l >> r;
    lr.emplace_back(l,r);
  }
  double ans = 0;
  for (int i=0; i<N; i++) {
    auto [l1,r1] = lr[i];
    for (int j=i+1; j<N; j++) {
      auto [l2,r2] = lr[j];
      ans += expected(l1,r1,l2,r2);
    }
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}

