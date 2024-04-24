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
  
  int H,W;
  cin >> H >> W;
  int m[52*52];
  int W2 = W+2;
  for (int i=0; i<=H+1; i++) {
    for (int j=0; j<=W+1; j++) {
      m[i*W2+j] = -1;
    }
  }
  for (int i=1; i<=H; i++) {
    string s; cin >> s;
    for (int j=1; j<=W; j++) {
      m[i*W2+j] = (int)(s[j-1]=='#');
    }
  }
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      int k = i*W2+j, bomb = 0;
      if (m[k]>0) {
        cout << '#';
        continue;
      }
      for (int di=-1; di<=1; di++) {
        for (int dj=-1; dj<=1; dj++) {
          int k1 = k+di*W2+dj;
          if (k!=k1 && m[k1]>=0) bomb+=m[k1];
        }
      }
      assert(bomb>=0 && bomb<9);
      cout << (char)('0'+bomb);
    }
    cout << endl;
  }
  return 0;
}

