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
  int X;
  cin >> X;
  if (X >= 90)
    print("expert");
  else if (X >= 70)
    print(90-X);
  else if (X >= 40)
    print(70-X);
  else
    print(40-X);
  return 0;
}
