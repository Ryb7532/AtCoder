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
  int res = 0;
  while (A!=B) {
    if (abs(A-B)>=8) {
      res++;
      if (A>B)
        A-=10;
      else
        A+=10;
    } else if (abs(A-B)>=3) {
      res++;
      if (A>B)
        A-=5;
      else
        A+=5;
    } else {
      res++;
      if (A>B)
        A-=1;
      else
        A+=1;
    }
  }
  print(res);
  return 0;
}
