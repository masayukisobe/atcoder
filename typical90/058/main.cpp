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

//#include <atcoder/all>
//using namespace atcoder;

const int inf = (1<<30);

int A(int x) {
  int y=0;
  int x1=x;
  while (x1>0) {
    y += x1%10;
    x1 /= 10;
  }
  return (x+y)%100000;
}

int memo[100001];

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  assert(A(99999)==44);

  int N;
  ll K;
  cin >> N >> K;
  vector<int> val(100001);
  vector<int> idx(100001,-1);
  int n = N, k = inf;
  for (int i=0; i<=min(K,100000LL); i++) {
    val[i] = n;
    if (i==K) {
      cout << n << endl;
      return 0;
    }
    if (idx[n]>=0) {
      k = i;
      break;
    }
    idx[n] = i;
    n = A(n);
  }
  assert(k!=inf && k<K);
  int loop_start = idx[val[k]];
  assert(loop_start>=0);
  int loop_size = k-loop_start;
  assert(loop_size>0);
  
  int r = (K-loop_start)%loop_size + loop_start;
  assert(r<=k);
  cout << val[r] << endl;
  return 0;
}

