#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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
  int A,B;
  cin >> A >> B;
  ll sumA=0, sumB=0;
  rep(i,A-1) {
    cout << i+1 << " ";
    sumA += i+1;
  }
  rep(i,B-1) {
    cout << -(i+1) << " ";
    sumB += i+1;
  }
  if (sumA > sumB) {
    cout << A << " " << -(sumA+A-sumB);
  } else {
    cout << -B << " " << sumB+B-sumA;
  }
  return 0;
}
