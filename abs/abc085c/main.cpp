#include <iostream>
#include <string>

using namespace std;

void check(int n,int y) {
  for (int i=0; i<=n; i++) {
    int sum1 = i*10;
    if (sum1>y) break;
    for (int j=0; j<=n-i; j++) {
      int sum2 = sum1 + j*5;
      if (sum2>y) break;
      int r = y-sum2;
      if (r==(n-i-j)) {
	cout << i << " " << j << " " << r << endl;
	return;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}

int main() {
  int n,y;
  cin >> n >> y;
  y /= 1000;
  check(n,y);
  return 0;
}

