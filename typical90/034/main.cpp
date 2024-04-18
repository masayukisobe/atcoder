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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  
  map<int,ll> c;
  int l=K,r=N+1;
  while (r-l>1) {
    int max_length = (l+r)/2;
    for (int i=0; i<N; i++) {
      c[a[i]] = 0;
    }
    bool found = false;
    int count = 0;
    for (int i=0; i<N; i++) {
      c[a[i]]++;
      if (c[a[i]]==1) count++;
      if (i>=max_length) {
        c[a[i-max_length]]--;
        if (c[a[i-max_length]]==0) count--;
      }
      int length = min(i+1,max_length);
      if (length==max_length && count<=K) {
        found = true;
        break;
      }
    }
    if (found) {
      l = max_length;
    } else {
      r = max_length;
    }
  }
  cout << l << endl;
  return 0;
}

