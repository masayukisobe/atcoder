#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[100009];
int b[100009];
int c[100009];

int main() {
  int n;  
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b,b+n);
  c[0] = 1;
  for (int i=1; i<n; i++) {
    c[i] = c[i-1];
    if (b[i]>b[i-1]) c[i]++;
  }
  for (int i=0; i<n; i++) {
    int j = lower_bound(b,b+n,a[i])-b;
    // assert(j<n)
    if (i>0) cout << " ";
    cout << c[j];
  }
  cout << endl;
  return 0;
}

