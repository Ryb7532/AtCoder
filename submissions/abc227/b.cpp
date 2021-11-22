#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  int res = 0;
  set<int> can;
  for (int a=1; a<143; a++) {
    for (int b=a; b<143; b++) {
      can.insert(4*a*b+3*a+3*b);
    }
  }
  rep(i,N) {
    int S;
    cin >> S;
    if (can.find(S) == can.end())
      res++;
  }
  print(res);
  return 0;
}
