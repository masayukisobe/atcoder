// #define _GLIBCXX_DEBUG
// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

//#include <atcoder/all>
//using namespace atcoder;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A.rbegin(),A.rend());

  int i=0,j=N-1;
  int gt=A[i++], lt=A[j--];
  ll ans = abs(gt-lt);
  for (int n=2; n<N; n++) {
    // debug(gt); debug(lt); debug(ans);
    int a = n%2==0 ? A[i++]: A[j--];
    if (n==N-1) {
      ans += max(abs(lt-a),abs(gt-a));
      break;
    } else if (n%2==0) {
      ans += abs(lt-a);
      lt = a;
    } else {
      ans += abs(gt-a);
      gt = a;
    }
    int x = max(lt,gt);
    int y = min(lt,gt);
    gt = x, lt = y;
  }
  //debug(gt); debug(lt); debug(ans);
  
  cout << ans << endl;
  return 0;
}

