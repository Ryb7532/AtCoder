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
  int A,B,C;
  cin >> A >> B >> C;
  char res;
  if (C%2==0) {
    if (abs(A)<abs(B))
      res = '<';
    else if (abs(A)>abs(B))
      res = '>';
    else
      res = '=';
  } else {
    if (A<B)
      res = '<';
    else if (A>B)
      res = '>';
    else
      res = '=';
  }
  print(res);
  return 0;
}
