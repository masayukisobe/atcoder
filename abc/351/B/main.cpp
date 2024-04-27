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
  vector<string> a(N),b(N);
  for (int i=0; i<N; i++) cin >> a[i];
  for (int i=0; i<N; i++) cin >> b[i];
  for (int i=0; i<N; i++) {
    if (a[i]==b[i]) continue;
    for (int j=0; j<N; j++) {
      if (a[i][j]!=b[i][j]) {
        cout << i+1 << " " << j+1 << endl;
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}

