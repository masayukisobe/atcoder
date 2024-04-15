// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
namespace {
//#pragma GCC diagnostic ignored "-Wunused-function"
//#include<atcoder/all>
//#pragma GCC diagnostic warning "-Wunused-function"
using namespace std;
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
const int INF = (1<<30);
}

int dis[205][205];
int ena[205][205];

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int H,W;
  cin >> H >> W;

  vector<string> s(H);
  int si,sj;
  int gi,gj;
  rep(i,H) {
    cin >> s[i];
    rep(j,W) {
      if (s[i][j]=='S') {
	si = i, sj = j;
      }
      if (s[i][j]=='T') {
	gi = i, gj = j;
      }
    }
  }

  const int di[4]={-1,1,0,0};
  const int dj[4]={0,0,-1,1};

  int N;
  cin >> N;
  rep(i,N) {
    int r,c,e;
    cin >> r >> c >> e;
    r--,c--;
    ena[r][c] = e;
  }
  rep(i,H) rep(j,W) dis[i][j]=INF;
  dis[gi][gj] = 0;

  queue<P> que;
  que.push({gi,gj});
  while (!que.empty()) {
    auto [i,j] = que.front();
    que.pop();
    rep(k,4) {
      int ni=i+di[k];
      int nj=j+dj[k];
      if (ni<0||ni>=H||nj<0||nj>=W) continue;
      if (s[ni][nj]=='#') continue;
      int d = dis[i][j]+1;
      if (ena[ni][nj]>=d) {
	d = 0;
      }
      if (chmin(dis[ni][nj],d)) que.push({ni,nj});
    }
  }
  
  cout << (dis[si][sj]==0 ? "Yes" : "No") << endl;
  return 0;
}

