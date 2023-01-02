#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  int N;
  cin >> N;
  vector<int> C(9);
  int minC = 1e6, argminC = 0;
  rep(i,9) {
    cin >> C[i];
    if (minC >= C[i]) {
      minC = C[i];
      argminC = i;
    }
  }
  rep(i,9) {
    C[i] -= minC;
  }
  if (N < minC) {
    print(0);
    return 0;
  }
  int dig = N / minC;
  int rest = N % minC;
  int k = 9 - 1;
  while (dig > 0) {
    if (rest >= C[k]) {
      cout << k+1;
      dig--;
      rest -= C[k];
    } else {
      k--;
    }
  }
  cout << endl;
  return 0;
}
