#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[100009];
int b[100009];
int c[100009];
int p[100009];


int main() {
  int n;  
  cin >> n;

  for (int i=2; i<=n; i++) {
    cin >> a[i];
  }
  for (int i=3; i<=n; i++) {
    cin >> b[i];
  }
  c[1]=0;
  c[2]=a[2];
  p[2]=1;
  for (int i=3; i<=n; i++) {
    int x = c[i-1]+a[i];
    int y = c[i-2]+b[i];
    if (x<y) {
      c[i] = x;
      p[i] = i-1;
    } else {
      c[i] = y;
      p[i] = i-2;
    }
  }
  vector<int> pp;
  int j = n;
  while (p[j]>1) {
    pp.push_back(p[j]);
    j = p[j];
  }
  cout << pp.size()+2 << endl << "1";
  for (int i=pp.size()-1; i>=0; i--) {
    cout << " " << pp[i];
  }
  cout << " " << n << endl;  
  return 0;
}

