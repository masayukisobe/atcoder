#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i=0; i<n; i++) {
    int t;
    cin >> t;
    a.push_back(t);
  }
  sort(a.rbegin(),a.rend());
  int result = 0;
  for (int i=0; i<n; i++) {
    if (i&1) {
      result -= a[i];
    } else {
      result += a[i];
    }
  }
  cout << result << endl;
  return 0;
}

