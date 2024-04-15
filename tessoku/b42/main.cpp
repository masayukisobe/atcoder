#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;  
  cin >> n;

  long r[4] = {0,0,0,0};
  for (int i=0; i<n; i++) {
    long a,b;
    cin >> a >> b;
    long r0=a+b;
    if (r0>0) r[0]+=r0;
    long r1=a-b;
    if (r1>0) r[1]+=r1;
    long r2=-a+b;
    if (r2>0) r[2]+=r2;
    long r3=-a-b;
    if (r3>0) r[3]+=r3;
  }

  cout << (*max_element(r,r+4)) << endl;
  return 0;
}

