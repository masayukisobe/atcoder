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

int a[11][11];
int m[11][11];
int f[11];

const int inf = (1<<30);

int dfs(int N, int i, int j, int cost) {
  if (i==N) return cost;
  int r=inf;
  for (int k=0; k<N; k++) {
    if (f[k]==1) continue;
    if (j>=0 && m[j][k]==1) continue;
    f[k] = 1;
    r = min(r,dfs(N,i+1,k,cost+a[k][i]));
    f[k] = 0;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> a[i][j];
    }
  }
  int M;
  cin >> M;
  for (int i=0; i<M; i++) {
    int x,y;
    cin >> x >> y;
    x--,y--;
    m[x][y] = 1;
    m[y][x] = 1;
  }
  int r = dfs(N,0,-1,0);
  cout << (r==inf ? -1 : r) << endl;
  return 0;
}

