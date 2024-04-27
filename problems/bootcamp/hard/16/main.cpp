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

int N,X,Y;
int dist(int i, int j) {
  int normal = j-i;
  int warp = abs(i-X)+1+abs(j-Y);
  return min(normal,warp);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> N >> X >> Y;
  vector<int> v(N);
  for (int i=1; i<=N; i++) {
    for (int j=i+1; j<=N; j++) {
      int k = dist(i,j);
      // debug(i); debug(j); debug(k);
      v[k]++;
    }
  }
  for (int k=1; k<N; k++) {
    cout << v[k] << endl;
  }
  return 0;
}

