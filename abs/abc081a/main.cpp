#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  
  cin >> s;
  int n = 0;
  for (char c : s) {
    if (c=='1') n++;
  }
  cout << n << endl;
  return 0;
}

