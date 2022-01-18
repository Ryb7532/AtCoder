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
  string S;
  cin >> S;
  vector<int> cnt(4,0);
  for (char c: S) {
    if (c == 'N') {
      cnt[0]++;
    } else if (c == 'S') {
      cnt[1]++;
    } else if (c == 'W') {
      cnt[2]++;
    } else {
      cnt[3]++;
    }
  }
  bool can = true;
  rep(i,2) {
    if (cnt[i]>0 && cnt[1-i]==0)
      can = false;
    if (cnt[2+i]>0 && cnt[3-i]==0)
      can = false;
  }
  print((can ? Yes : No));
  return 0;
}
