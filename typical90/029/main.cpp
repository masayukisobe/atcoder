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

int _id() { return 0; }
int _max(int x, int y) { return max(x,y); }

#include <atcoder/all>
using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int W,N;
  cin >> W >> N;
  vector<int> p;
  vector<int> idx(W+1,-1);
  vector<ii> lr(N);
  for (int i=0; i<N; i++) {
    int l,r;
    cin >> l >> r;
    lr[i] = ii(l,r);
    if (idx[l]<0) { idx[l]=0; p.push_back(l); }
    if (idx[r]<0) { idx[r]=0; p.push_back(r); }
  }
  sort(p.begin(),p.end());
  for (int i=0; i<p.size(); i++) idx[p[i]]=i;
  lazy_segtree<int,_max,_id,int,_max,_max,_id> h(2*N);
  for (int i=0; i<N; i++) {
    int l = lr[i].first;
    int r = lr[i].second;
    int m = h.prod(idx[l],idx[r]+1);
    h.apply(idx[l],idx[r]+1,m+1);
    cout << m+1 << endl;
  }
  return 0;
}

