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
  
  ll N;
  cin >> N;
  for (ll h=1; h<=3500; h++) {
    for (ll w=1; w<=3500; w++) {
      ll a = N*h*w;
      ll b = 4*h*w-N*(h+w);
      if (b>0 and a>=b and a%b==0) {
        ll n = a/b;
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }
  return 0;
}

