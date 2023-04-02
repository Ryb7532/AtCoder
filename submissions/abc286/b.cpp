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
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  string S;
  cin >> N >> S;
  string res;
  res.push_back(S[0]);
  rep(i,N-1) {
    if (res.back() == 'n' && S[i+1] == 'a')
      res.push_back('y');
    res.push_back(S[i+1]);
  }
  print(res);
  return 0;
}
