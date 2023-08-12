#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
  }
  ll v = sum / N, u = sum % N;
  ll minus = 0, plus = 0;
  rep(i,N) {
    if (A[i] < v)
      minus += v - A[i];
    else if (A[i] > v) {
      plus += A[i] - v;
      if (u > 0) {
        u--;
        plus--;
      }
    }
  }
  print(minus+u);
  return 0;
}
