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

int N, Q;
int x[60],y[60],z[60];
ll w[60];

using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> N >> Q;
  for (int i=0; i<Q; i++) {
    int a,b,c;
    ll d;
    cin >> a >> b >> c >> d;
    x[i] = a-1;
    y[i] = b-1;
    z[i] = c-1;
    w[i] = d;
  }
  mint count1 = 1;
  for (int i=0; i<60; i++) {
    ll mask = (1LL<<i);
    mint count2 = 0;
    for (int j=0; j<(1<<N); j++) {
      bool ok = true;
      for (int k=0; k<Q; k++) {
        int q = 0;
        q ^= j&(1<<x[k]);
        q ^= j&(1<<y[k]);
        q ^= j&(1<<z[k]);
        if (bool(q)!=bool(w[k]&mask)) {
          ok = false;
          break;
        }
      }
      if (ok) count2++;
    }
    count1 *= count2;
  }
  cout << count1.val() << endl;
  return 0;
}

