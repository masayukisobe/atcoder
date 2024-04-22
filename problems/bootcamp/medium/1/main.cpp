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
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  
  vector<bool> visited(N);
  int b=0;
  for (int n=1; n<=N; n++) {
    visited[b] = true;
    b = A[b]-1;
    if (b==1) {
      cout << n << endl;
      return 0;
    }
    if (visited[b]) break;
  }
  cout << -1 << endl;
  return 0;
}

