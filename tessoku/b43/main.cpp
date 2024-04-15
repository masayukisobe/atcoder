#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;  
  cin >> n >> m;
  int *a = new int[n];
  for (int i=0; i<n; i++) {
    a[i] = m;
  }
  for (int i=0; i<m; i++) {
    int j;
    cin >> j;
    a[j-1]--;
  }
  for (int i=0; i<n; i++) {
    cout << a[i] << endl;
  }
  delete [] a;
  return 0;
}

