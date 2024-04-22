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

using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  ll N,K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  mint count1 = 0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      if (a[i] > a[j]) count1++;
    }
  }
  mint count2 = 0;
  sort(a.begin(),a.end());
  for (int i=0; i<N; i++) {
    auto it = lower_bound(a.begin()+i,a.end(),a[i]+1);
    count2 += (int)(a.end()-it);
  }
  mint count3 = (K-1)*K/2;
  mint result = count1*mint(K)+count2*count3;
  cout << result.val() << endl;
  return 0;
}

