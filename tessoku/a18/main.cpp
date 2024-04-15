#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[69];
bool dp[69][10009];

int main() {
  int n,s;  
  cin >> n >> s;
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int j=0; j<=s; j++) dp[0][j]=(j==0);
  for (int i=1; i<=n; i++) {
    int t = a[i];
    for (int j=0; j<t; j++) {
      dp[i][j] = dp[i-1][j];
    }
    for (int j=t; j<=s; j++) {
      dp[i][j] = dp[i-1][j] || dp[i-1][j-t];
    }
  }
  cout << (dp[n][s] ? "Yes" : "No") << endl;
  
  return 0;
}

