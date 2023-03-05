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
  string S,T;
  cin >> S >> T;
  int s,t,i,j;
  s = S.size();
  t = T.size();
  i = 0;
  j = 0;
  bool flag = true;
  while (i < s) {
    if (j < t && S[i] != T[j]) {
      flag = false;
      break;
    }
    int k = i, l = j;
    while (k < s && S[k] == S[i])
      k++;
    while (l < t && T[l] == T[j])
      l++;
    k -= i;
    l -= j;
    if ((k == 1 && l != 1) || k > l) {
      flag = false;
      break;
    }
    i += k;
    j += l;
  }
  if (j < t)
    flag = false;
  print((flag ? Yes : No));
  return 0;
}
