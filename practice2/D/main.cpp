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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }

#include <atcoder/all>
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N,M;
  cin >> N >> M;
  mf_graph<int> graph(N*M+2);

  auto index =
    [&M](int i, int j) {
      int c = (i+j)%2;
      int k = (i*M+j)+2;
      return ii(c,k);
    };
  auto to_i = [&M](int k) { return (k-2)/M; };
  auto to_j = [&M](int k) { return (k-2)%M; };

  int di[4] = {1,-1,0,0};
  int dj[4] = {0,0,1,-1};

  vector<string> s(N);
  for (int i=0; i<N; i++) {
    cin >> s[i];
    assert(s[i].size()==M);
  }
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (s[i][j]=='#') {
        continue;
      }
      auto [c,k] = index(i,j);
      if (c==0) {
        graph.add_edge(0,k,1);
      } else if (c==1) {
        graph.add_edge(k,1,1);
      } else {
        assert(false);
      }

      if (c!=0) continue;

      for (int m=0; m<4; m++) {
        int i1 = i+di[m];
        int j1 = j+dj[m];
        if (i1<0 || i1>=N || j1<0 || j1>=M) {
          continue;
        }
        if (s[i1][j1]=='#') {
          continue;
        }
        auto [c1,k1] = index(i1,j1);
        assert(c1==1);
        graph.add_edge(k,k1,1);
      }
    }
  }

  int maxflow = graph.flow(0,1);
  cout << maxflow << endl;
  for (auto& e : graph.edges()) {
    if (e.from==0 || e.to==1 || e.flow==0) {
      continue;
    }
    int fi = to_i(e.from);
    int fj = to_j(e.from);
    int ti = to_i(e.to);
    int tj = to_j(e.to);
    if (fi==ti) {
      if (fj<tj) {
        s[fi][fj] = '>';
        s[ti][tj] = '<';
      } else if (fj>tj) {
        s[fi][fj] = '<';
        s[ti][tj] = '>';
      } else {
        assert(false);
      }
    } else if (fj==tj) {
      if (fi<ti) {
        s[fi][fj] = 'v';
        s[ti][tj] = '^';
      } else if (fi>ti) {
        s[fi][fj] = '^';
        s[ti][tj] = 'v';
      } else {
        assert(false);
      }
    } else {
      assert(false);
    }
  }

  for (auto s1 : s) {
    cout << s1 << endl;
  }
  return 0;
}

