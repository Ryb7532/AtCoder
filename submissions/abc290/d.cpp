#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


ll GCD(ll a, ll b) {
  if (b==0) {
    return a;
  }
  return GCD(b, a%b);
}


int main() {
  int T;
  cin >> T;
  rep(_,T) {
    ll N,D,K;
    cin >> N >> D >> K;
    K--;
    ll gcd = GCD(D,N);
    int N_ = N/gcd;
    print((K/N_ + (K*D))%N);
  }
  return 0;
}
