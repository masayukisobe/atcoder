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

  int N,Q;
  cin >> N >> Q;
  fenwick_tree<ll> fw(N);
  for (int i=0; i<N; i++) {
    int a;
    cin >>a;
    fw.add(i,a);
  }
  for (int i=0; i<Q; i++) {
    int a,b,c;
    cin >>a>>b>>c;
    if (a==0) {
      fw.add(b,c);
    } else {
      cout << fw.sum(b,c)<<endl;
    }
  }
  return 0;
}

