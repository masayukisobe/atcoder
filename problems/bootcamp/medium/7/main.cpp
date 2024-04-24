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
  
  int N;
  cin >> N;
  string s;
  cin >> s;
  assert(s.size()==N);
  char n[26];
  int ans = 0;
  // split [0,i), [i,N)
  for (int i=1; i<N; i++) {
    for (int j=0; j<26; j++) n[j]=0;
    for (int j=0; j<i; j++) n[s[j]-'a']|=1;
    for (int j=i; j<N; j++) n[s[j]-'a']|=2;
    int count = 0;
    for (int j=0; j<26; j++) count += (int)(n[j]==3);
    ans = max(ans, count);
  }
  cout << ans << endl;
  return 0;
}

