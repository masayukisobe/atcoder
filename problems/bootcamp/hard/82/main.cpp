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
  vector<ll> A(N);
  vector<ll> B(N);
  for (int i=0; i<N; i++) {
    cin >> A[i] >> B[i];
    A[i] += B[i];
  }
  ll ans = -accumulate(B.begin(),B.end(),0LL);
  sort(A.rbegin(),A.rend());
  for (int i=0; i<N; i+=2) ans+=A[i];
  cout << ans << endl;
  return 0;
}

