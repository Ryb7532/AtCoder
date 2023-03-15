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
  vector<int> cnt(13,0);
  rep(i,5) {
    int N;
    cin >> N;
    cnt[--N]++;
  }
  bool three = false, two = false;
  rep(i,13) {
    if (cnt[i] == 3)
      three = true;
    if (cnt[i] == 2)
      two = true;
  }
  print((three & two ? Yes : No));
  return 0;
}
