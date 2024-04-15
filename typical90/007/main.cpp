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
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int b;
    cin >> b;
    int best = (1<<30);
    auto it = lb(a.begin(),a.end(),b);
    if (it!=a.end()) {
      best = min(best,(*it)-b);
    }
    if (it!=a.begin()) {
      best = min(best,b-(*(it-1)));
    }
    cout << best << endl;
  }
  return 0;
}

