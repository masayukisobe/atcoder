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
  
  int N,S;
  cin >> N >> S;
  vector<int> check(S+1);
  vector<vector<pair<int,string>>> working(2);
  working[0].emplace_back(0,"");  
  for (int i=1; i<=N; i++) {
    auto &prev = working[(i-1)&1];
    auto &current = working[i&1];
    current.clear();
    int a,b; cin >> a >> b;
    for (auto &p : prev) {
      auto w = p.first;
      auto &s = p.second;
      if (w+a<=S && check[w+a]<i) {
        if (i==N && w+a==S) {
          cout << s+'A' << endl;
          return 0;
        }
        check[w+a] = i;
        current.emplace_back(w+a,s+'A');
      }
      if (w+b<=S && check[w+b]<i) {
        if (i==N && w+b==S) {
          cout << s+'B' << endl;
          return 0;
        }
        check[w+b] = i;
        current.emplace_back(w+b,s+'B');
      }
    }
  }
  cout << "Impossible" << endl;
  return 0;
}

