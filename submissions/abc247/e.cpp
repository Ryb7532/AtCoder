#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N+1);
  rep(i,N) {
    cin >> A[i];
  }
  A[N] = 0;
  int i = 0, j = 0;
  long res = 0;
  while (i < N) {
    if (A[i] > X || A[i] < Y) {
      i++;
      continue;
    }
    j = i;
    while (j <= N) {
      if (A[j] > X || A[j] < Y)
        break;
      j++;
    }
    int lx = i, ly = i, x = -1, y = -1;
    while (i < j) {
      if (A[i] == X) {
        if (y >= 0) {
          res += (y-lx+1) * (j-i);
          ly = y+1;
          x = i;
          y = -1;
        } else {
          x = i;
        }
      }
      if (A[i] == Y) {
        if (x >= 0) {
          res += (x-ly+1) * (j-i);
          lx = x+1;
          y = i;
          x = -1;
        } else {
          y = i;
        }
      }
      i++;
    }
  }
  print(res);
  return 0;
}
