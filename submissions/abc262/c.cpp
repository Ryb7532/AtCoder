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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  ll same = 0, res = 0;
  rep(i,N) {
    if (A[i] == i+1)
      same++;
    else {
      if (A[i] > i+1 && A[A[i]-1] == i+1)
        res++;
    }
  }
  res += same * (same - 1) / 2;
  print(res);
  return 0;
}
