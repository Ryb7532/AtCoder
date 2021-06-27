#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
  vector<int> h(N+1);
  rep(i,N) {
    cin >> h[i];
  }
  h[N] = 1e9+1;
  int s=0, ans=0;
  bool east = false;
  rep1(i,N) {
    if (h[i]>h[i-1]) {
      if (east) {
        ans = max(ans,i-s);
        east = false;
        s = i-1;
      }
    } else {
      if (!east) {
        east = true;
      }
    }
  }
  ans = max(ans,N-s);
  print(ans);
  return 0;
}
