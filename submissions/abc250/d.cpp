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
  ll N;
  cin >> N;
  ll res = 0;
  vector<ll> P;
  for (ll q=2; 2*q*q*q <= N; q++) {
    int i = 0;
    bool isPrime = true;
    while (i < P.size() && P[i]*P[i] <= q) {
      if (q%P[i] == 0) {
        isPrime = false;
        break;
      }
      i++;
    }
    if (isPrime) {
      rep(i,P.size()) {
        if (N / P[i] >= q*q*q) {
          res++;
        } else {
          break;
        }
      }
      P.push_back(q);
    }
  }
  print(res);
  return 0;
}
