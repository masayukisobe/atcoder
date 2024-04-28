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
  for (int i=0; i<N; i++) cin >> A[i];
  
  vector<int> res(N);
  for (int i=N; i>=1; i--) {
    int k = 0;
    for (int j=i+i; j<=N; j+=i) {
      k ^= res[j-1];
    }
    if (k!=A[i-1]) res[i-1] = 1;
  }
  
  vector<int> ans(N);
  int n = 0;
  for (int i=0; i<N; i++) {
    if (res[i]) ans[n++] = i+1;
  }
  cout << n << endl;
  for (int i=0; i<n; i++) {
    if (i>0) cout << " ";
    cout << ans[i];
  }
  if (n>0) cout << endl;
  return 0;
}

