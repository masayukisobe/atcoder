#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n,a,b;
  
  cin >> n >> a >> b;
  int result = 0;
  for (int i=1; i<=n; i++) {
    int t = 0;
    int j = i;
    while (j>0) {
      t += j%10;
      j/=10;
    }
    if (t>=a && t<=b) {
      result+=i;
    }
  }
  cout << result << endl;
  return 0;
}

