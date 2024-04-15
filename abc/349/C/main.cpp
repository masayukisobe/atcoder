// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
namespace {
using namespace std;
  //#pragma GCC diagnostic ignored "-Wunused-function"
  //n#include<atcoder/all>
  //#pragma GCC diagnostic warning "-Wunused-function"
  //using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  string s;  
  cin >> s;
  string t;  
  cin >> t;
  int n = s.size();
  int j=0;
  bool ans=false;
  rep(i,n) {
    if (toupper(s[i])==t[j]) {
      j++;
      if (t[2]=='X' ? j==2 : j==3) {
	ans = true;
	break;
      }
    }
  }
  cout <<(ans ? "Yes" : "No")<<endl;
  return 0;
}

