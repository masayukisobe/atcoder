#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int w[109];
int v[109];
int dp[109][100009];

const int V=1000;


int main() {
  int N, W;  
  cin >> N >> W;
  for (int i=1; i<=N; i++) {
    cin >> w[i] >> v[i];
  }
  int NV = N * V;
  for (int j=0; j<=NV; j++) dp[0][j] = j==0 ? 0 : W+1;
  for (int i=1; i<=N; i++) {
    int wi = w[i];
    int vi = v[i];
    for (int j=0; j<vi; j++) {
      dp[i][j] = dp[i-1][j];
    }
    for (int j=vi; j<=NV; j++) {
      int t = W+1;
      t = min(t,dp[i-1][j]);
      t = min(t,dp[i-1][j-vi]+wi);
      dp[i][j] = t;
    }
  }
  for (int j=NV; j>=0; j--) {
    if (dp[N][j]<=W) {
      cout << j << endl;
      break;
    }
  }
  
  return 0;
}

