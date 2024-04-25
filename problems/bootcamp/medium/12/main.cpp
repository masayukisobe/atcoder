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
  vector<bool> v(H*W);
  for (int i=0; i<H; i++) {
    string s; cin >> s;
    for (int j=0; j<W; j++) {
      int k = i*W+j;
      v[k] = (s[j]=='#');
    }
  }
  vector<bool> yoko(H);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (v[i*W+j]) {
        yoko[i] = true;
        break;
      }
    }
  }
  vector<bool> tate(W);
  for (int j=0; j<W; j++) {
    for (int i=0; i<H; i++) {
      if (v[i*W+j]) {
        tate[j] = true;
        break;
      }
    }
  }
  for (int i=0; i<H; i++) {
    if (!yoko[i]) continue;
    for (int j=0; j<W; j++) {
      if (!tate[j]) continue;
      cout << (v[i*W+j] ? '#' : '.');
    }
    cout << endl;
  }
  return 0;
}

