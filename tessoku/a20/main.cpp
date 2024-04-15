#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2009][2009];

int main() {
  string s,t;  
  cin >> s >> t;
  for (int i=0; i<=s.size(); i++) dp[i][0] = 0;
  for (int j=0; j<=t.size(); j++) dp[0][j] = 0;
  for (int i=1; i<=s.size(); i++) {
    for (int j=1; j<=t.size(); j++) {
      dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      if (s[i-1]==t[j-1]) {
	dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
      }
    }
  }
  cout << dp[s.size()][t.size()] << endl;
  return 0;
}

