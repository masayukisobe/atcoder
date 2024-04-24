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
  vector<int> pop(9);
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    pop[min(8,a/400)]++;
  }
  int ans_min = 0;
  int ans_max = 0;
  for (int i=0; i<=8; i++) {
    if (i<8) {
      ans_max += (pop[i]>0);
      ans_min += (pop[i]>0);
    } else {
      ans_max += pop[i];
      if (pop[i]>0 && ans_min==0) ans_min = 1;
    }
  }
  cout << ans_min << " " << ans_max << endl;
  return 0;
}

