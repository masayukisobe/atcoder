#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d;
  for (int i=0; i<n; i++) {
    int t;
    cin >> t;
    d.push_back(t);
  }
  sort(d.rbegin(),d.rend());
  int result = 0;
  for (int i=0; i<n; i++) {
    if (i==0 || d[i]<d[i-1]) {
      result++;
    }
  }
  cout << result << endl;
  return 0;
}

