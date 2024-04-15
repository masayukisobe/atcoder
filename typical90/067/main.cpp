// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define lb lower_bound
#define ub upper_bound

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  string s;
  int K;
  cin >> s >> K;
  ull N = 0;
  int l = s.size();
  for (int i=0; i<l; i++) {
    N += (ull)(s[i]-'0') << (3*(l-1-i));
  }
  if (N==0) {
    cout << "0" << endl;
    return 0;
  }
  for (int i=0; i<K; i++) {
    ull p = 0;
    ull q = 1;
    ull n = N;
    while (n>0) {
      int j = n%9;
      if (j==8) j=5;
      p += j*q;
      q *= 8;
      n /= 9;
    }
    N = p;
  }
  vector<ull> r;
  while (N>0) {
    r.push_back(N%8);
    N/=8;
  }
  for (int i=r.size()-1; i>=0; i--) {
    cout << r[i];
  }
  cout << endl;
  return 0;
}

