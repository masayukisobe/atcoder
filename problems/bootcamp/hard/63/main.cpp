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

int getmask(int n) {
  int mask = 0;
  while (n>0) {
    mask |= 1<<(n%10);
    n/=10;
  }
  return mask;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N,K;
  cin >> N >> K;
  int dislike = 0;
  for (int i=0; i<K; i++) {
    int d; cin >> d;
    dislike |= 1<<d;
  }
  for (int n=N; n<=99999; n++) {
    if (getmask(n)&dislike)
      continue;
    cout << n << endl;
    break;
  }
  return 0;
}

