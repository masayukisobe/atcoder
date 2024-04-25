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
  vector<string> ss(H+2);
  ss[0]=string('.',W+2);
  for (int i=1; i<=H; i++) {
    string s; cin >> s;
    ss[i] = '.'+s+'.';
  }
  ss[H+1]=string('.',W+2);
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      if (ss[i][j]!='#') continue;
      int c = 0;
      if (ss[i-1][j]=='#') c++;
      if (ss[i+1][j]=='#') c++;
      if (ss[i][j-1]=='#') c++;
      if (ss[i][j+1]=='#') c++;
      if (c==0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

