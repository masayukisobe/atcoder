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
  vector<int> x(N);
  int j=0;
  for (int i=0; i<N; i++) {
    int j1 = (j+1)%N;
    int j2 = (j+2)%N;
    x[j2] = x[j]+A[j1]-A[j];
    j = j2;
  }
  int diff = (A[0]-(x[0]+x[1]))/2;
  for (int i=0; i<N; i++) {
    if (i>0) cout << " ";
    cout << 2*(x[i]+diff);
  }
  cout << endl;
  return 0;
}

