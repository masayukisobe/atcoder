#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[40];
long long p[67000];
long long q[67000];

void prepare(int i, int limit,long long *r) {
  for (int mask = 0; mask<limit; mask++) {
    int j = 0;
    int t = mask;
    r[mask] = 0;
    while (t) {
      if (t&1) {
	r[mask] += a[i+j];
      }
      j++;
      t>>=1;
    }
  }
  sort(r,r+limit);
}

int main() {
  int n, k;  
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int h = n/2;

  int limit1 = (1<<h);
  int limit2 = (1<<(n-h));
  prepare(0,limit1,p);
  prepare(h,limit2,q);

  bool ans=false;
  for (int mask=0; mask<limit2; mask++) {
    int lb=lower_bound(p,p+limit1,k-q[mask])-p;
    //cout << "check" << mask << " " << q[mask] << " " << k-q[mask] << endl;
    //cout << lb << " " << p[lb] << endl;
    if (lb<limit1 && p[lb]+q[mask]==k) {
      ans = true;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}

