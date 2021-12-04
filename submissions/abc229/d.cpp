#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S;
  int K;
  cin >> S >> K;
  int n = S.size();
  int l=0, r=0, ans=0;
  while (l < n) {
    while (r < n) {
      if (S[r] == '.') {
        if (K == 0) {
          break;
        }
        K--;
      }
      r++;
    }
    ans = max(ans, r-l);
    if (S[l] == '.') {
      K++;
    }
    l++;
  }
  print(ans);
  return 0;
}
