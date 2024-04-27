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
  
  int N,M;
  cin >> N >> M;
  vector<ll> a(N), b(M);
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    a[i] = 0;
    for (int j=0; j<N; j++) {
      if (s[j]=='#') a[i] |= 1<<j;
    }
  }
  for (int i=0; i<M; i++) {
    string s; cin >> s;
    b[i] = 0;
    for (int j=0; j<M; j++) {
      if (s[j]=='#') b[i] |= 1<<j;
    }
  }
  ll mask = (1<<M)-1;
  for (int i=0; i+M<=N; i++) {
    for (int j=0; j+M<=N; j++) {
      bool match = true;
      for (int k=0; k<M; k++) {
        if (((a[i+k]>>j)&mask)!=b[k]) {
          match = false;
          break;
        }
      }
      if (match) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

