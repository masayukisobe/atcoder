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

void dfs(int n, int m, int k) {
  vector<char> v;
  if (n==0) {
    while (m>1) {
      v.push_back(m&1 ? '(' : ')');
      m>>=1;
    }
    for (int i=v.size()-1; i>=0; i--) cout << v[i];
    cout << endl;
    return;
  }
  if (n-k>=2) dfs(n-1,m<<1|1,k+1);
  if (k>0) dfs(n-1,m<<1,k-1);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  if (N%2==0) {
    dfs(N,1,0);
  }
  return 0;
}

