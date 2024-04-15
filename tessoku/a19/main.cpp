#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int w[109];
int v[109];
long dp[109][100009];

int main() {
  int N, W;  
  cin >> N >> W;
  for (int i=1; i<=N; i++) {
    cin >> w[i] >> v[i];
  }
  for (int j=0; j<=W; j++) dp[0][j]=0;
  for (int i=1; i<=N; i++) {
    int wi = w[i];
    int vi = v[i];
    for (int j=0; j<wi; j++) {
      dp[i][j] = dp[i-1][j];
    }
    for (int j=wi; j<=W; j++) {
      dp[i][j] = max(dp[i-1][j],dp[i-1][j-wi]+vi);
    }
  }
  long ans = 0;
  for (int j=0; j<=W; j++) {
    ans = max(ans,dp[N][j]);
  }
  cout << ans << endl;
  
  return 0;
}

