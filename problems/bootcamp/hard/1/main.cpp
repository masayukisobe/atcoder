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
  
  string S;
  cin >> S;
  int N = S.size();

  auto shift =
    [&S](int i)->int {
      if (S[i]=='L') return i-1;
      if (S[i]=='R') return i+1;
      assert(false);
    };
  
  // calc after 10 times
  vector<int> after10(N,-1);
  for (int i=0; i<N; i++) {
    int k = i;
    for (int j=0; j<10; j++) k = shift(k);
    after10[i] = k;
  }
  
  auto &afterMany = after10;
  vector<int> temp(N);
  for (int c=2; c<=100; c++) {
    for (int i=0; i<N; i++) temp[i] = 0;
    for (int i=0; i<N; i++) {
      int k = i;
      for (int j=0; j<10; j++) k = afterMany[k];
      temp[i] = k;
    }
    for (int i=0; i<N; i++) afterMany[i] = temp[i];
  }
  
  vector<int> result(N,0);
  for (int i=0; i<N; i++) {
    result[afterMany[i]]++;
  }
  for (int i=0; i<N; i++) {
    if (i>0) cout << " ";
    cout << result[i];
  }
  cout << endl;
  return 0;
}

