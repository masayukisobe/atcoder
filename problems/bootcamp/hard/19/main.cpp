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
  
  int H,W,N;
  cin >> H >> W >> N;
  vector<int> v(H*W);
  int k=0; 
  for (int i=1; i<=N; i++) {
    int a; cin >> a;
    for (int j=0; j<a; j++) {
      v[k++] = i;
    }
  }
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int k = (i%2==0 ? i*W+j : i*W+(W-1-j));
      if (j>0) cout << " ";
      cout << v[k];
    }
    cout << endl;
  }
  return 0;
}

