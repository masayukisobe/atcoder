#include <iostream>
#include <string>

using namespace std;

bool check(int* a, int n) {
  for (int i=0; i<n; i++) {
    if (a[i]&1)
      return false;
  }
  for (int i=0; i<n; i++) {
    a[i]>>=1;
  }
  return true;
}

int main() {
  int n;
  
  cin >> n;
  int* a = new int[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  
  int m = 0;
  while (check(a,n)) {
    m++;
  }
  cout << m << endl;
  delete a;
  return 0;
}

