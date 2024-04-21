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

string s;
int N;
vector<int> match;

char change(char c) {
  if ('a'<=c && c<='z') return (char)(c-'a'+'A');
  if ('A'<=c && c<='Z') return (char)(c-'A'+'a');
  return c;
}

void dfs(bool rev, int i, int j) {
  //cout << s.substr(i,j-i+1) << endl;
  if (rev)  {
    for (int k=j; k>=i; k--) {
      if (s[k]==')') {
        dfs(!rev,match[k]+1,k-1);
        k = match[k];
        continue;
      }
      cout << s[k];
    }
  } else {
    for (int k=i; k<=j; k++) {
      if (s[k]=='(') {
        dfs(!rev,k+1,match[k]-1);
        k = match[k];
        continue;
      }
      cout << s[k];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  cin >> s;
  N = s.size();
  match.resize(N);
  for (auto& m:match) m=-1;
  
  int depth=0;
  vector<int> stack;
  for (int i=0; i<N; i++) {
    char c=s[i];
    if (c=='(') {
      stack.push_back(i);
      depth++;
    }
    else if (c==')') {
      match[i] = stack.back();
      match[stack.back()] = i;
      stack.pop_back();
      depth--;
    }
    else if (depth&1) {
      s[i] = change(c);
    }
  }
  dfs(false,0,N-1);
  cout << endl;
  return 0;
}

