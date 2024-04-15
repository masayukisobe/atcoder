#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int X,Y;
  cin >> X >> Y;

  vector<int> x;
  vector<int> y;
  x.push_back(X);
  y.push_back(Y);
  int n=0;
  
  while (X>1 || Y>1) {
    if (X>Y) {
      X -= Y;
    } else {
      Y -= X;
    }
    x.push_back(X);
    y.push_back(Y);
    n++;
  }

  cout << n << endl;
  for (int i=n-1; i>=0; i--) {
    cout << x[i] << " " << y[i] << endl;
  }
  
  return 0;
}

