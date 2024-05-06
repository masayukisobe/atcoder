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
  ll x;
  cin >> N >> x;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  ll before  = accumulate(A.begin(),A.end(),0LL);

  A[0] = min(x,A[0]);
  for (int i=1; i<N; i++) {
    ll eat = max(0LL,A[i]+A[i-1]-x);
    assert(eat<=A[i]);
    A[i] -= eat;
  }
  ll after  = accumulate(A.begin(),A.end(),0LL);
  cout << before-after << endl;
  return 0;
}

