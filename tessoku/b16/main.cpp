#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int h[100009];
int c[100009];

inline int abs(int x) {
  return (x<0 ? -x : x);
}

int main() {
  int n;  
  cin >> n;
  for (int i=1; i<=n; i++) cin >> h[i];

  c[1] = 0;
  c[2] = abs(h[2]-h[1]);
  for (int i=3; i<=n; i++) {
    c[i] = min(c[i-2]+abs(h[i]-h[i-2]),c[i-1]+abs(h[i]-h[i-1]));
  }
  cout << c[n] << endl;
  return 0;
}

