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

#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i=0; i<N; i++) {
    int p; cin >> p;
    P[i] = p-1;
  }
  string S;
  cin >> S;

  vector<bool> use1(N);
  mint ans1=1;
  for (int i=0; i<N; i++) {
    int j = P[i];
    int left = j;
    int right = (j+1)%N;
    char c = S[j];
    if (use1[right]) {
      if (c=='?') ans1 *= 2;
    } else {
      if (c=='R') ans1 *= 0;
    }
    use1[left] = true;
  }

  vector<bool> use2(N);
  mint ans2=1;
  for (int i=0; i<N; i++) {
    int j = P[i];
    int left = j;
    int right = (j+1)%N;
    char c = S[j];
    if (use2[left]) {
      if (c=='?') ans2 *= 2;
    } else {
      if (c=='L') ans2 *= 0;
    }
    use2[right] = true;
  }

  mint ans = ans1+ans2;
  cout << ans.val() << endl;
  return 0;
}

