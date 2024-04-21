// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  string s;
  cin >> N >> K >> s;
  assert(s.size()==N);
  vector<char> best(K);
  for (int i=0; i<K; i++) {
    best[i] = s[N-K+i];
  }
  for (int i=N-K-1; i>=0; i--) {
    char c1 = s[i];
    for (int j=0; j<K; j++) {
      char c2 = best[j];
      if (c1 <= c2) {
        best[j] = c1;
        c1 = c2;
      } else break;
    }
  }
  for (int i=0; i<K; i++) {
    cout << best[i];
  }
  cout << endl;
  return 0;
}

