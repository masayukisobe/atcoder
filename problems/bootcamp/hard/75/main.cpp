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

  int N,K;
  cin >> N >> K;
  string s;
  cin >> s;
  int f=0;
  for (int i=1; i<N; i++) {
    if (s[i]==s[i-1]) f++;
  }
  int k2 = min((N-1-f)/2,K);
  K -= k2;
  int k1 = K>0 and (N-1-f)%2==1 ? 1 : 0;
  cout << f+2*k2+k1 << endl;
  return 0;
}

