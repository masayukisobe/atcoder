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
  vector<int> count(100001);
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    if (a>0) count[a-1]++;
    if (a<100000) count[a+1]++;
    count[a]++;
  }
  auto it = max_element(count.begin(),count.end()) ;
  cout << *it << endl;
  return 0;
}

