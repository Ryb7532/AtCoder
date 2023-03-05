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
  map<char, int> cnt;
  string S;
  cin >> S;
  rep(i,3) {
    cnt[S[i]-'a']++;
  }
  rep(i,26) {
    if (cnt[i] == 1) {
      print(char('a'+i));
      return 0;
    }
  }
  print(-1);
  return 0;
}
