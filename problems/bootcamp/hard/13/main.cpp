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
  vector<int> v(N);
  for (int i=0; i<N; i++) v[i] = s[i]-'0';
  int ans=0;
  for (int i=0; i<1000; i++) {
    int a = i/100;
    int b = (i/10)%10;
    int c = i%10;
    
    int j=0;
    while (v[j]!=a && j<N) j++;
    if (j==N) continue;
    
    j++;
    while (v[j]!=b && j<N) j++;
    if (j==N) continue;
    
    j++;
    while (v[j]!=c && j<N) j++;
    if (j==N) continue;
    
    ans++;
  }
  cout << ans << endl;
  return 0;
}

