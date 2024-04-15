#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum[100009];

int main() {
  int n, k;
  cin >> n >> k;
  sum[0]=0;
  for (int i=1; i<=n; i++) {
    int a;
    cin >> a;
    sum[i] = a+sum[i-1];
  }
  int ans=0;
  int j=0;
  for (int i=1; i<=n; i++) {
    while (j<=n && sum[j]-sum[i-1]<=k) {
      j++;
    }
    ans+=j-i; // (j-1) - (i-1)
  }
  cout << ans << endl;
  return 0;
}



