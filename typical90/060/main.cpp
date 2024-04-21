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

void lis(vector<int> &a, vector<int> &dp) {
  vector<int> work;
  for (int i=0; i<a.size(); i++) {
    auto it = lower_bound(work.begin(),work.end(),a[i]);
    dp.push_back(it-work.begin());
    if (it==work.end()) {
      work.push_back(a[i]);
    } else {
      *it = a[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  vector<int> up,down;
  lis(a,up);
  reverse(a.begin(),a.end());
  lis(a,down);
  int ans = 0;
  for (int i=0; i<N; i++) {
    ans = max(ans, up[i]+down[N-1-i]+1);
  }
  cout << ans << endl;
  return 0;
}

