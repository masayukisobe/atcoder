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

int gcd(int a,int b) {
  int x = max(a,b);
  int y = min(a,b);
  while (y>0) {
    int r = x%y;
    x = y;
    y = r;
  }
  return x;
}

//#include <atcoder/all>
//using namespace atcoder;
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  int maxa = -1;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    maxa = max(maxa,A[i]);
  }
  int c = A[0];
  for (int i=1; i<N; i++) {
    c = gcd(c,A[i]);
  }
  bool possible = K%c==0 && K<=maxa;
  cout << (possible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}

