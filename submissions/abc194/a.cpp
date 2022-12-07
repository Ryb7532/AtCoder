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
  int A,B;
  cin >> A >> B;
  int C = A+B;
  if (C>=15 && B>=8)
    print(1);
  else if (C>=10 && B>=3)
    print(2);
  else if (C>=3)
    print(3);
  else
    print(4);
  return 0;
}
