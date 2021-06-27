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
  string c;
  cin >> N >> c;
  int ans = 0, l=0,r=N-1;
  while (1) {
    while (c[r] == 'W') {
      r--;
    }
    while (c[l] == 'R') {
      l++;
    }
    if (r-l<=0)
      break;
    ans++;
    r--;
    l++;
  }
  print(ans);
  return 0;
}
