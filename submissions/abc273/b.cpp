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
  vector<ll> X(16, 0);
  int K;
  string S;
  cin >> S >> K;
  int s = S.size();
  rep(i,s) {
    X[i] = S[s-1-i]-'0';
  }
  rep(i,K) {
    if (X[i] >= 5)
      X[i+1]++;
    X[i] = 0;
  }
  ll res = 0;
  rep(i,16) {
    res *= 10;
    res += X[15-i];
  }
  print(res);
  return 0;
}
