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
  int A, B, C, D, E, F, X;
  cin >> A >> B >> C >> D >> E >> F >> X;
  int Taka, Aoki;
  Taka = (X / (A+C)) * B * A;
  Aoki = (X / (D+F)) * E * D;
  Taka += min(B * A, (X % (A + C)) * B);
  Aoki += min(E * D, (X % (D + F)) * E);
  if (Taka == Aoki) {
    print("Draw");
  } else if (Taka > Aoki) {
    print("Takahashi");
  } else {
    print("Aoki");
  }
  return 0;
}
