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
  
  ll N,A,X,Y;
  cin >> N >> A >> X >> Y;

  double x = X;
  double y = Y;

  ll cost=0;
  ll n = N;
  while (n>6) {
    double n0 = n;
    
    // case1: cost X
    double n1 = n/A;
    
    // case2: cost Y
    double n2 = 0;
    for (int i=2; i<=6; i++) {
      double t = n/A;
      n2 += t/6.0;
    }

    if ((n-n1)/x >= (n-n2)/y) {
      n = n/A;
    } else {
      
    }
    
  }
  
  cout << endl;
  return 0;
}

