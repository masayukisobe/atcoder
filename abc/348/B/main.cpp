#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int x[109];
int y[109];

int distance(int dx, int dy) {
  return dx*dx+dy*dy;
}

int main() {
  int n;  
  cin >> n;

  for (int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i=0; i<n; i++) {
    int best = n;
    int dmax = -1;
    for (int j=0; j<n; j++) {
      if (i!=j) {
	int d = distance(x[j]-x[i],y[j]-y[i]);
	if (best==n || distance(x[j]-x[i],y[j]-y[i])>dmax) {
	  best = j;
	  dmax = d;
	}
      }
    }
    cout << best+1 << endl;
  }
  return 0;
}

