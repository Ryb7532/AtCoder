#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  int res = 0;
  for (int i=1; i<=N; i++) {
    int tmp = i;
    bool is7 = false;
    while (tmp != 0) {
      if (tmp%10 == 7)
        is7 = true;
      tmp /= 10;
    }
    tmp = i;
    while (tmp != 0) {
      if (tmp%8 == 7)
        is7 = true;
      tmp /= 8;
    }
    if (!is7)
      res++;
  }
  print(res);
  return 0;
}
