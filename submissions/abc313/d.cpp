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
  int N,K;
  cin >> N >> K;
  vector<int> A(N, -1), B(K+1);
  rep(i,K+1) {
    cout << "?";
    rep(j,K+1) {
      if (i == j)
        continue;
      cout << " " << j+1;
    }
    cout << endl;
    cin >> B[i];
  }
  vector<bool> sameA0(K);
  sameA0[0] = true;
  rep(i,K) {
    sameA0[i+1] = B[0] == B[i+1];
  }
  int cntT = 0;
  rep(i,K+1) {
    cntT += sameA0[i];
  }
  if (cntT%2) {
    int j = 0;
    while (sameA0[j])
      j++;
    A[0] = B[j];
  } else {
    A[0] = B[0];
  }
  rep(i,K) {
    if (sameA0[i+1])
      A[i+1] = A[0];
    else
      A[i+1] = 1 - A[0];
  }
  int cnt = 0;
  rep(i,K-1) {
    cnt += A[i];
  }
  rep(i,K+1,N) {
      cout << "?";
    rep(j,K-1) {
      cout << " " << j+1;
    }
    cout << " " << i+1 << endl;
    int r;
    cin >> r;
    if (r == cnt%2)
      A[i] = 0;
    else
      A[i] = 1;
  }
  cout << "!";
  rep(i,N) {
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}
