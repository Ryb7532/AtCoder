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
  int S,T;
  cin >> S >> T;
  int res = 0;
  for (int a=0; a<=100; a++) {
    for (int b=0; b<=100; b++) {
      if (a+b>S)
        continue;
      for (int c=0; c<=100; c++) {
        if (a+b+c>S)
          continue;
        if (a*b*c<=T)
          res++;
      }
    }
  }
  print(res);
  return 0;
}
