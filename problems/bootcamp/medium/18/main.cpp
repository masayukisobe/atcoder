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

int c[9];

bool check() {
  int a1=0;
  int b1=c[0]-a1;
  int a2=c[3]-b1;
  int b2=c[1]-a1;
  int a3=c[6]-b1;
  int b3=c[2]-a1;
  if (a1+b1!=c[0]) return false;
  if (a1+b2!=c[1]) return false;
  if (a1+b3!=c[2]) return false;
  if (a2+b1!=c[3]) return false;
  if (a2+b2!=c[4]) return false;
  if (a2+b3!=c[5]) return false;
  if (a3+b1!=c[6]) return false;
  if (a3+b2!=c[7]) return false;
  if (a3+b3!=c[8]) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  for (int i=0; i<9; i++) cin >> c[i];
  cout << (check() ? "Yes" : "No") << endl;
  return 0;
}

