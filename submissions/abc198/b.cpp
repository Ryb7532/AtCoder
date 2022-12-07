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
  string N;
  cin >> N;
  int len = N.size();
  int cnt0 = 0, j = len-1;
  while (N[j]=='0') {
    cnt0++;
    j--;
  }
  bool can = true;
  int i=0;
  while (i<=j-i) {
    if (N[i]!=N[j-i]) {
      can = false;
      break;
    }
    i++;
  }
  print((can ? Yes : No));
  return 0;
}
