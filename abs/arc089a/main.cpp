#include <iostream>
#include <string>

using namespace std;

int ABS(int x) {
  return x>=0 ? x : -x;
}

bool possible(int dt, int dx, int dy) {
  int ax = abs(dx);
  int ay = abs(dy);
  int d = ax + ay;
  return (d<=dt && d%2==dt%2);
}


int main() {
  int n;
  
  cin >> n;
  bool result = true;
  int pt=0,px=0,py=0;
  for (int i=0; i<n; i++) {
    int t,x,y;
    cin >> t >> x >> y;
    if (!possible(t-pt,x-px,y-py)) {
      result=false;
      break;
    }
    
    pt = t;
    px = x;
    py = y;
  }
  
  cout << (result ? "Yes" : "No") << endl;
  return 0;
}

