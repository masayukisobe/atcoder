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
  vector<int> v(N);
  int n = 0;
  for (int i=0; i<N; i++) {
    cin >> v[i];
    n = max(n,v[i]);
  }
  int m = n/2;
  int r = 0;
  for (int i=0; i<N; i++) {
    if (v[i]==n) continue;
    int x = min(v[i],n-v[i]);
    int y = min(r,n-r);
    if (m-x < m-y) r = v[i];
  }
  
  cout << n << " " << r << endl;
  return 0;
}

