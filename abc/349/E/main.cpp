// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
namespace {
using namespace std;
  //#pragma GCC diagnostic ignored "-Wunused-function"
  //n#include<atcoder/all>
  //#pragma GCC diagnostic warning "-Wunused-function"
  //using namespace atcoder;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
}

int a[3][3];
int f[3][3];

bool check(int sign) {
  int r1=0,r2=0;
  for (int i=0; i<3; i++) {
    int s=0,t=0;
    for (int j=0; j<3; j++) {
      if (f[i][j]==sign) s++;
      if (f[j][i]==sign) t++;
    }
    if (s==3||t==3) return true;
    if (f[i][i]==sign) r1++;
    if (f[2-i][i]==sign) r2++;
  }
  return r1==3||r2==3;
}

int dfs(int depth, long long diff,int sign) {
  if (check(-sign)) return -sign;
  if (depth==9) return (diff > 0 ? 1 : -1);
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (f[i][j]==0) {
	f[i][j] = sign;
	int t=dfs(depth+1,diff+sign*a[i][j],-sign);
	f[i][j] = 0;
	if (t==sign) return sign;
      }
    }
  }
  return -sign;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cin >> a[i][j];
      f[i][j] = 0;
    }
  }
  cout << (dfs(0,0,1)>0 ? "Takahashi" : "Aoki") << endl;
  return 0;
}

