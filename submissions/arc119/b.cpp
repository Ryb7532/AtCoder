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
  int N;
  string S,T,U;
  cin >> N >> S >> T;
  vector<int> s,t;
  rep(i,N) {
    if (S[i]=='0')
      s.push_back(i);
    if (T[i]=='0')
      t.push_back(i);
  }
  if (s.size() != t.size()) {
    print(-1);
    return 0;
  }
  int res = 0;
  int n = s.size();
  rep(i,n) {
    if (s[i]!=t[i])
      res++;
  }
  print(res);
  return 0;
}
