#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;  
  cin >> n;
  vector<pair<int,int>> v;
  for (int i=0; i<n; i++) {
    int a,c;
    cin >> a >> c;
    v.push_back({c,a});
  }
  sort(v.begin(),v.end());

  int best = v[0].second;
  for (int i=1; i<n; i++) {
    if (v[i].first!=v[i-1].first) {
      best = max(best,v[i].second);
    }
  }
  cout << best << endl;
  return 0;
}

