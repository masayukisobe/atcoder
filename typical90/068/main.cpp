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
  
  int N,Q;
  cin >> N >> Q;
  vector<ll> right(N,-1);
  vector<ll> right2(N,-1);
  vector<ll> left(N,-1);
  vector<ll> left2(N,-1);
  for (int i=0; i<Q; i++) {
    int t,x,y;
    ll v;
    cin >> t >> x >> y >> v;
    x--,y--;
    //debug(x); debug(y);
    if (t==0) {
      //assert(x+1==y);
      //assert(right[x]<0 || right[x]==v);
      //assert(left[y]<0 || left[y]==v);
      right[x]=left[y]=v;
      if (right[y]>=0) {
        right2[x]=right[y]-v;
      }
      if (left[x]>=0) {
        left2[y]=left[x]-v;
      }
    } else {
      if (y<x) {
        while (y<x-1) {
          if (left2[x]<0) break;
          v += left2[x]; x-=2;
        }
        while (y<x) {
          if (left[x]<0) break;
          v = left[x--]-v;
        }
      } else if (x<y) {
        while (x+1<y) {
          if (right2[x]<0) break;
          v += right2[x]; x+=2;
        }
        while (x<y) {
          if (right[x]<0) break;
          v = right[x++]-v;
        }
      }
      if (x==y) {
        cout << v << endl;
      } else {
        cout << "Ambiguous" << endl;
      }
    }
  }
  return 0;
}

