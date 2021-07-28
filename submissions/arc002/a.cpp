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

bool check_uruu(int y) {
  if (y%400==0)
    return true;
  else if (y%100==0)
    return false;
  else if (y%4==0)
    return true;
  else
    return false;
}

int main() {
  int Y;
  cin >> Y;
  print((check_uruu(Y) ? YES : NO));
  return 0;
}
