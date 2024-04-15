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
  
  int Q;
  cin >> Q;
  deque<int> q;
  for (int i=0; i<Q; i++) {
    int t,x;
    cin >> t >> x;
    if (t==1) {
      q.push_front(x);
    } else if (t==2) {
      q.push_back(x);
    } else if (t==3) {
      cout << q.at(x-1) << endl;
    } else {
      assert(false);
    }
  }
  return 0;
}

