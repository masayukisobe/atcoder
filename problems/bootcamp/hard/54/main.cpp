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
#define sortv(v) sort((v).begin(),(v).end())
#define rsortv(v) sort((v).rbegin(),(v).rend())
#define debug(x) cout << #x << ": " << x << endl

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int X,Y,A,B,C;
  cin >> X >> Y >> A >> B >> C;
  vector<int> a(A),b(B),c(C);
  for (int i=0; i<A; i++) cin >> a[i];
  for (int i=0; i<B; i++) cin >> b[i];
  for (int i=0; i<C; i++) cin >> c[i];
  rsortv(a);
  rsortv(b);
  rsortv(c);

  ll ans = 0;
  ans += accumulate(a.begin(),a.begin()+X,0LL);
  ans += accumulate(b.begin(),b.begin()+Y,0LL);
  
  using que_t = priority_queue<int, vector<int>, greater<int>>;
  que_t q1(a.begin(),a.begin()+X);
  que_t q2(b.begin(),b.begin()+Y);
  
  for (int v : c) {
    int x = q1.top();
    int y = q2.top();
    if (v<=x && v<=y) break;
    if (x<=y) {
      q1.pop();
      q1.push(v);
      ans += v-x;
      continue;
    } else {
      q2.pop();
      q2.push(v);
      ans += v-y;
      continue;
    }
  }
  cout << ans << endl;
  return 0;
}

