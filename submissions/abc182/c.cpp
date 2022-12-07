#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S;
  cin >> S;
  int n = S.length();
  vec<int> r(n);
  vec<int> cnt(3,0);
  int sum = 0, res = -1;
  rep(i,n) {
    r[i] = (S[i]-'0')%3;
    cnt[r[i]]++;
    sum = (sum+r[i])%3;
  }
  if (sum == 0)
    res = 0;
  else {
    if (cnt[sum]>0)
      res = 1;
    else if (cnt[3-sum]>=2)
      res = 2;
  }
  if (res == n)
    res = -1;
  print(res);
  return 0;
}
