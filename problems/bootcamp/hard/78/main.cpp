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
  
string s;
int K;
  cin >> s >> K;
  
  unordered_set<string> us;
  priority_queue<string> q;
  
  int L = s.size();
  for (int l=1; l<=L; l++) {
    for (int i=0; i+l<=L; i++) {
      string t = s.substr(i,l);
      if (not us.contains(t) and (q.size()<K or q.top()>t)) {
        q.push(t);
        us.insert(t);
        if (q.size()>K) {
          us.erase(q.top());
          q.pop();
        }
      }
    }
  }
  cout << q.top() << endl;
  return 0;
}

