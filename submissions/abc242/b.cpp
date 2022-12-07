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
  vector<int> cnt(26,0);
  for (char c: S) {
    cnt[c-'a']++;
  }
  for (int i=0; i<26; i++) {
    char c = 'a'+i;
    while(cnt[i]) {
      cout << c;
      cnt[i]--;
    }
  }
  cout << endl;
  return 0;
}
