#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N;
  cin >> N;
  vi c(N+1);
  vi seq(N,1);
  rep(i,N) {
    cin >> c[i];
  }
  int b=-1;
  rep(i,N) {
    if (c[i] != c[(i+1)%N]) {
      b = i+1;
      break;
    }
  }
  if (b == -1) {
    print(-1);
    return 0;
  }
  int m = 0,l = 1;
  rep(i,N) {
    if (c[(i+b)%N] == c[(i+b+1)%N]) {
      l++;
    } else {
      m = max(m,l);
      l=1;
    }
  }
  print((m+1)/2);
  return 0;
}
