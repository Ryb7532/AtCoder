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
  int N;
  cin >> N;
  vector<ll> A(N);
  ll Xor = 0;
  rep(i,N) {
    cin >> A[i];
    Xor = Xor ^ A[i];
  }
  bool win = N%2==1;
  rep(i,N) {
    if (Xor == A[i])
      win = true;
  }
  print((win ? "Win" : "Lose"));
  return 0;
}
