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
  
  int H,W,K;
  cin >> H >> W >> K;
  vector<bool> A(H*W);
  vector<int> row(H);
  for (int i=0; i<H; i++) {
    string s; cin >> s;
    for (int j=0; j<W; j++) {
      if (s[j]=='#') {
        A[i*W+j]=true;
        row[i]++;
      }
    }
  }
  vector<int> c(H*W);
  int p = 0;
  int min_i = -1;
  for (int i=0; i<H; i++) {
    int r = row[i];
    if (r>0) {
      p++;
      if (min_i<0) min_i = i;
      for (int j=0; j<W; j++) {
        int k = i*W+j;
        c[k] = p;
        if (A[k]) {
          r--;
          if (r>0) p++;
        }
      }
    }
  }
  for (int i=0; i<H; i++) {
    if (row[i]==0) {
      int i1 = max(i-1,min_i);
      for (int j=0; j<W; j++) {
        int k = i*W+j;
        int k1 = i1*W+j;
        c[k] = c[k1];
      }
    }
  }
  for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        if (j>0) cout << " ";
        cout << c[i*W+j];
      }
      cout << endl;
  }
  return 0;
}

