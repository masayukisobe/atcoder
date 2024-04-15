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
  
  int N,L,K;
  cin >> N >> L >> K;

  vector<int> a(N+1);
  for (int i=1; i<=N; i++) {
    cin >> a[i];
  }
  int left = 0;
  int right = L+1;
  while (left < right-1) {
    // cout << left << " " << right << endl;
    int x = (left+right)/2;
    int t=0,k=0;
    for (int i=1; i<=N; i++) {
      int b = a[i]-a[i-1];
      if (t+b>=x) {
        k++;
        t = 0;
      } else {
        t += b;
      }
    }
    t += L-a[N];
    if (k>K || k==K && t>=x) {
      left = x;
    } else {
      right = x;
    }
  }
  cout << left << endl;
  return 0;
}

