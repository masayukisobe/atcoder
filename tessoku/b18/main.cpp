#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[69];
bool dp[69][10009];
bool use[69][10009];

int main() {
  int n, s;  
  cin >> n >> s;
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int j=0; j<=s; j++) dp[0][j] = (j==0);
  for (int i=1; i<=n; i++) {
    int t = a[i];
    for (int j=0; j<t; j++) {
      dp[i][j] = dp[i-1][j];
      use[i][j] = false;
    }
    for (int j=t; j<=s; j++) {
      dp[i][j] = dp[i-1][j] || dp[i-1][j-t];
      use[i][j] = dp[i-1][j-t];
    }
  }

  if (!dp[n][s]) {
    cout << "-1" << endl;
    return 0;
  }

  vector<int> ans;
  int j=s;
  for (int i=n; i>=1; i--) {
    if (use[i][j]) {
      ans.push_back(i);
      j-=a[i];
    }
  }
  // assert(j==0)
  sort(ans.begin(),ans.end());
  cout << ans.size() << endl;
  for (int i=0; i<ans.size(); i++) {
    if (i>0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  
  return 0;
}

