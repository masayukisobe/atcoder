#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[100009];


int main() {
  int n;  
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a,a+n);
  
  int q;
  cin >> q;
  for (int i=0; i<q; i++) {
    int x;
    cin >> x;
    int w = lower_bound(a,a+n,x)-a;
    cout << w << endl;
  }
  return 0;
}

