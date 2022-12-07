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
  int N,K;
  cin >> N >> K;
  vec<int> P(N,0);
  rep(i,N) {
    rep(_,3) {
      int p;
      cin >> p;
      P[i] += p;
    }
  }
  vec<int> Q = P;
  sort(rall(Q));
  int pointK = Q[K-1];
  rep(i,N) {
    if (P[i]+300-pointK >= 0)
      print(Yes);
    else
      print(No);
  }
  return 0;
}
