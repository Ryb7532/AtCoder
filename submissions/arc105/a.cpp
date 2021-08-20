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
  vec<int> C(4);
  int sum = 0;
  rep(i,4) {
    cin >> C[i];
    sum += C[i];
  }
  bool can = false;
  rep(i,4) {
    if (2*C[i]==sum)
      can = true;
  }
  for (int i=0; i<3; i++) {
    for (int j=i+1; j<4; j++) {
      if (2*(C[i]+C[j]) == sum)
        can = true;
    }
  }
  print((can ? Yes : No));
  return 0;
}
