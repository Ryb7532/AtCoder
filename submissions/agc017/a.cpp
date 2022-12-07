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


vector<vector<ll>> comb(51, vector<ll>(51, 0));
void init() {
  rep(i,51) {
    comb[i][0] = 1;
  }
  for (int i=1; i<51; i++) {
    for (int j=1; j<=i; j++) {
      comb[i][j] = comb[i-1][j]+comb[i-1][j-1];
    }
  }
}

int main() {
  int N,P;
  cin >> N >> P;
  int odd = 0;
  rep(i,N) {
    int A;
    cin >> A;
    odd += A%2;
  }
  init();
  ll res = 0;
  if (P==1) {
    for (int i=1; i<=odd; i+=2) {
      for (int j=0; j<=N-odd; j++) {
        res += comb[odd][i] * comb[N-odd][j];
      }
    }
  } else {
    for (int i=0; i<=odd; i+=2) {
      for (int j=0; j<=N-odd; j++) {
        res += comb[odd][i] * comb[N-odd][j];
      }
    }
  }
  print(res);
  return 0;
}
