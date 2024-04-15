#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[512][512];
int p[512];

int main() {
  int n;  
  cin >> n;
  for (int i=0; i<n ;i++) {
    p[i] = i;
    for (int j=0; j<n ;j++) {
      cin >> a[i][j];
    }
  }

  int m;
  cin >> m;
  for (int k=0; k<m ;k++) {
    int q,x,y;
    cin >> q >> x >> y;
    x -= 1;
    y -= 1;
    if (q==1) {
      int t = p[x];
      p[x] = p[y];
      p[y] = t;
    } else {
      cout << a[p[x]][y] << endl;
    }
  }

  return 0;
}

