#include <iostream>
#include <string>

using namespace std;

string dict[4] = {
		  string("dream"),
		  string("erase"),
		  string("eraser"),
		  string("dreamer") 
};

bool eq(string &s, int i, int j, string &d) {
  for (int k=i; k<j; k++) {
    if (s[k]!=d[k-i]) return false; 
  }
  return true;
}

bool dfs(string &s, int i) {
  int n = s.size();
  if (i==n) return true;
  for (string& d : dict) {
    int m = d.size();
    if (n>=m) {
      if (eq(s,i,i+m,d) && dfs(s,i+m))
	return true;
    }
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  cout << (dfs(s,0) ? "YES" : "NO") << endl;
  return 0;
}

