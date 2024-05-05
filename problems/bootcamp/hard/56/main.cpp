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

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<ll> a(N),b(N);
  for (int i=0; i<N; i++) cin >> a[i];
  for (int i=0; i<N; i++) cin >> b[i];
  ll n=0,m=0;
  for (int i=0; i<N; i++) {
    if (a[i]>b[i]) {
      n += a[i]-b[i];
    }
    if (a[i]<b[i]) {
      int diff = b[i]-a[i];
      m += diff/2 + diff%2;
    }
  }
  ll asum = accumulate(a.begin(),a.end(),0LL);
  ll bsum = accumulate(b.begin(),b.end(),0LL);
  ll ab_sub = bsum - asum;
  cout << (n<=ab_sub and m<=ab_sub ? "Yes" : "No") <<endl;
  return 0;
}

