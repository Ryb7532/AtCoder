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
  int N,M,K;
  cin >> N >> M >> K;
  rep(i,N+1) {
    int cnt = i*M;
    rep(j,M+1) {
      if (K == cnt + (N-i)*j - i*j) {
        print(Yes);
        return 0;
      }
    }
  }
  print(No);
  return 0;
}
