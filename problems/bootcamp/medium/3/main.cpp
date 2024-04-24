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
  
  string s;
  cin >> s;
  int N=s.size()+1;
  vector<int> A(N,0);
  
  int a1=0;
  for (int i=0; i<N-1; i++) {
    if (s[i]=='<') {
      a1++;
      A[i+1] = max(a1,A[i+1]);
    } else {
      a1=0;
    }
  }
  int a2=0;
  for (int i=N-2; i>=0; i--) {
    if (s[i]=='>') {
      a2++;
      A[i] = max(a2,A[i]);
    } else {
      a2=0;
    }
  }
  const bool debug = false;
  if (debug) {
    for (int i=0; i<N; i++) {
      if (i>0) cout << " ";
      cout << A[i];
    }
    cout << endl;
  }

  ll ans = 0;
  for (int i=0; i<N; i++) {
    ans += A[i];
  }
  cout << ans << endl;
  return 0;
}

