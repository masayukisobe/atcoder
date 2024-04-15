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

  int N;
  ull P,Q;
  cin >> N >> P >> Q;
  vector<ull> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  auto dfs =
    [&a,&N,&P,&Q](auto self, int k, int i, ull r) -> ull {
      if (k==0) return (r==Q ? 1 : 0);
      ull c = 0;
      for (int j=i; j+k<=N; j++) {
        c += self(self,k-1,j+1,(r*a[j])%P);
      }
      return c;
    };

  cout << dfs(dfs,5,0,1) << endl;
  return 0;
}

