#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int h[100009];
int c[100009];
int p[100009];

inline int abs(int x) {
  return (x<0 ? -x : x);
}

int main() {
  int n;  
  cin >> n;
  for (int i=1; i<=n; i++) cin >> h[i];

  c[1] = 0;
  c[2] = abs(h[2]-h[1]);
  p[2] = 1;
  for (int i=3; i<=n; i++) {
    int x = c[i-2]+abs(h[i]-h[i-2]);
    int y = c[i-1]+abs(h[i]-h[i-1]);
    if (x<y) {
      c[i] = x;
      p[i] = i-2;
    } else {
      c[i] = y;
      p[i] = i-1;
    }
  }
  vector<int> pp;
  int j=n;
  while (p[j]>1) {
    pp.push_back(p[j]);
    j = p[j];
  }
  cout << pp.size()+2 << endl;
  cout << "1";
  for (int i=pp.size()-1; i>=0; i--) {
    cout << " " << pp[i];
  }
  cout << " " << n << endl;
  return 0;
}

