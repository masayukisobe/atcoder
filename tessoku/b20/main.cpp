#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2009][2009];

int main() {
  string s,t;  
  cin >> s >> t;
  int ns = s.size();
  int nt = t.size();

  dp[0][0] = 0;
  for (int i=1; i<=ns; i++) dp[i][0] = i; // del x i times
  for (int j=1; j<=nt; j++) dp[0][j] = j; // insert x j times

  for (int i=1; i<=ns; i++) {
    for (int j=1; j<=nt; j++) {
      int cost = ns+nt;
      cost = min(cost,dp[i-1][j]+1); // del
      cost = min(cost,dp[i][j-1]+1); // insert
      if (s[i-1]==t[j-1]) {
	cost = min(cost,dp[i-1][j-1]); // match
      } else {
	cost = min(cost,dp[i-1][j-1]+1); // edit
      }
      dp[i][j] = cost;
    }
  }
  cout << dp[ns][nt] << endl;
  return 0;
}

