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
  
  int H,W;
  cin >> H >> W;
  const int H2 = H+2;
  const int W2 = W+2;
  const vector<int> dk4 = {-1,1,-W2,W2};

  vector<int> v(H2*W2,-1);
  queue<ii> q;
  for (int i=0; i<H; i++) {
    string s; cin >> s;
    for (int j=0; j<W; j++) {
      int k = (i+1)*W2+(j+1);
      if (s[j]=='#') {
        q.emplace(k,0);
      } else {
        v[k] = 0;
      }
    }
  }
  auto check = [&](int k, int d) {
    if (v[k]==0) {
      v[k] = d;      
      q.emplace(k,d);
    }
  };
  while (!q.empty()) {
    auto [k,d] = q.front(); q.pop();
    for (auto dk : dk4) check(k+dk,d+1);
  }
  auto it = max_element(v.begin(),v.end());
  cout << max(0,*it) << endl;
  return 0;
}

