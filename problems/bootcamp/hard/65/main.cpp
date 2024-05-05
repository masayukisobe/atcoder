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
  sort(A.begin(),A.end());
  int r[2]={0,0};
  int n=1;
  for (int i=1; i<N; i++) {
    if (A[i]==A[i-1]) n++;
    else {
      r[n%2]++;
      n = 1;
    }
  }
  r[n%2]++;
  //debug(r[0]); debug(r[1]);
  ll ans = r[0]+r[1];
  if (r[0]%2==1) ans--;
  cout << ans << endl;
  return 0;
}

