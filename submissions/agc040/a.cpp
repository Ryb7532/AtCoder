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
  int N = S.size();
  ll res = 0;
  int i = 0;
  while (i<N) {
    int j = i;
    while (i<N && S[i]=='<') {
      i++;
    }
    ll m0 = i-j;
    res += m0*(m0-1)/2;
    j = i;
    while (i<N && S[i]=='>') {
      i++;
    }
    ll m1 = i-j;
    res += m1*(m1-1)/2;
    res += max(m0,m1);
  }
  print(res);
  return 0;
}
