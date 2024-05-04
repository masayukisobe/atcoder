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

#include <atcoder/all>
using namespace atcoder;

int op1(int a, int b) { return max(a, b); }
int e1() { return -1; }

int op2(int a, int b) { return min(a, b); }
int e2() { return 1<<30; }

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  cin >> N >> K;
  vector<ii> v;
  for (int i=0; i<N; i++) {
    int x; cin >> x;
    v.emplace_back(x,i);
  }
  sort(v.begin(),v.end());
  vector<int> w(N);
  for (int i=0; i<N; i++) {
    w[i] = v[i].second;
  }
  segtree<int,op1,e1> segmax(w);
  segtree<int,op2,e2> segmin(w);
  int ans = 1<<30;
  for (int i=0; i+K<=N; i++) {
    assert(v[i].first==i+1);
    int smax = segmax.prod(i,i+K);
    int smin = segmin.prod(i,i+K);
    ans = min(ans,smax-smin);
  }
  cout << ans << endl;
  return 0;
}

