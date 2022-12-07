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
  cin >> N;
  vector<int> A(N);
  ll res = 0;
  rep(i,N) {
    cin >> A[i];
  }
  int i=N-1;
  while(i>=0) {
    res += A[i];
    bool flag = true;
    if (A[i]>i)
      flag = false;
    while(i>0 && A[i]==A[i-1]+1) {
      i--;
    }
    if (i>0 && A[i-1]<A[i])
      flag = false;
    if (!flag) {
      res = -1;
      break;
    }
    i--;
  }
  print(res);
  return 0;
}
