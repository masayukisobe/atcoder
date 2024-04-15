#include <iostream>
#include <string>

using namespace std;

int main() {
  int a,b,c,x;
  int n = 0;

  cin >> a >> b >> c >> x;

  for (int i=0; i<=a; i++) {
    int ti = i*500;
    if (ti>x) break;
    for (int j=0; j<=b; j++) {
      int tj = ti+j*100;
      if (tj>x) break;
      int r = x-tj;
      if (r%50==0 && r/50<=c) n++;
    }
  }

  cout << n << endl;
  return 0;
}

