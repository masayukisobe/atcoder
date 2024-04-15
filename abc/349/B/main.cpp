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
  int n = s.size();
  VI c(30);
  rep(i,('z'-'a')+1) {
    c[i]=0;
  }
  rep(i,n) {
    c[(s[i]-'a')]++;
  }
  VI v(n);
  rep(i,n+1) v[i]=0;
  rep(i,('z'-'a')+1) {
    v[c[i]]++;
    //cout << ('a'+i)<<" " << c[i] << " " << v[c[i]]<< endl;
  }
  bool ans=true;
  rep(i,n+1) {
    if (i==0) continue;
    if (!(v[i]==0 ||v[i]==2)) {
      ans=false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}

