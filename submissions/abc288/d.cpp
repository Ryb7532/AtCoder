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


int main() {
  int N,K;
  cin >> N >> K;
  vector<ll> A(N+2,0);
  rep(i,N) {
    cin >> A[i+1];
  }
  vector<ll> B(N+1,0);
  rep(i,N+1) {
    B[i] = A[i+1]-A[i];
  }
  vector<vector<ll>> S(K, vector<ll>(N/K+2, 0));
  rep(i,K) {
    for (int j=0; j*K+i<=N; j++) {
      S[i][j+1] = S[i][j] + B[j*K+i];
    }
  }
  int Q;
  cin >> Q;
  rep(_,Q) {
    int l,r;
    cin >> l >> r;
    l--;
    bool flag = true;
    rep(i,K) {
      int il = (l-i+K-1)/K;
      int ir = (r-i)/K+1;
      ll sum = S[i][ir]-S[i][il];
      if (l%K == i)
        sum += A[l];
      if (r%K == i)
        sum -= A[r+1];
      if (sum != 0)
        flag = false;
    }
    printyesno(flag);
  }
  return 0;
}
