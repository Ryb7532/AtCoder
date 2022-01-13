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
  string S;
  cin >> N >> S;
  ll res = 0, seq = 0;
  rep(i,N-1) {
    if (S[i]==S[i+1])
      seq++;
    else
      seq = 0;
    res += seq;
  }
  print(res);
  return 0;
}
