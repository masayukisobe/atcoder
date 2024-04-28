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
  vector<iii> v;
  for (int i=0; i<N-1; i++) {
    int c,s,f; cin >> c >> s >> f;
    v.emplace_back(c,s,f);
  }
  for (int i=0; i<N-1; i++) {
    int t = 0;
    for (int j=i; j<N-1; j++) {
      auto [c,s,f] = v[j];
      if (t<s) t=s;
      int r = t%f;
      if (r>0) t+=f-r;
      t+=c;
    }
    cout << t << endl;
  }
  cout << 0 << endl;
  return 0;
}

