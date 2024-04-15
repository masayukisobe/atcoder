// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
namespace {
using namespace std;
  //#pragma GCC diagnostic ignored "-Wunused-function"
  //n#include<atcoder/all>
  //#pragma GCC diagnostic warning "-Wunused-function"
  //using namespace atcoder;
}

uint64_t gcd(uint64_t a, uint64_t b) {
  uint64_t x,y;
  x = max(a,b);
  y = min(a,b);
  while (y!=0) {
    uint64_t t = x%y;
    x = y;
    y = t;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,M;
  cin >> N >> M;
  vector<uint64_t> A(N);
  vector<uint64_t> dp(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
    dp[i] = 0;
  }

  for (int i=1; i<=N; i++) {
    if (dp[i-1]==0) {
      if (A[i-1]==M) dp[i]++;
      
    } else {
    }
  }
  
  
  cout << endl;
  return 0;
}

