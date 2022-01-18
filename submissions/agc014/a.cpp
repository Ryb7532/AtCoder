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
  ll A,B,C;
  cin >> A >> B >> C;
  if (A>B)
    swap(A,B);
  if (C<A)
    swap(A,C);
  if (B>C)
    swap(B,C);
  set<tuple<ll,ll,ll>> used;
  used.insert({A,B,C});
  int res = 0;
  while (A%2==0 && B%2==0 && C%2==0) {
    ll a,b,c;
    a = (B+C)/2;
    b = (C+A)/2;
    c = (A+B)/2;
    A = c;
    B = b;
    C = a;
    res++;
    if (used.find({A,B,C}) != used.end()) {
      res = -1;
      break;
    }
    used.insert({A,B,C});
  }
  print(res);
  return 0;
}
