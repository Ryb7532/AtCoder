#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N;
  cin >> N;
  ll A[N+1];
  A[0] = 0;
  rep1(i,N) {
    cin >> A[i];
    A[i] += A[i-1];
  }
  int l = 1, r = 3;
  ll ans = 1e9;
  reps(i,2,N-1) {
    while (l<i-1 && abs(2*A[l]-A[i])>abs(2*A[l+1]-A[i])) {
      l++;
    }
    while (r<N-1 && abs(2*A[r]-A[N]-A[i])>abs(2*A[r+1]-A[N]-A[i])) {
      r++;
    }
    ll P, Q, R, S, tmp;
    P = A[l];
    Q = A[i]-A[l];
    R = A[r]-A[i];
    S = A[N]-A[r];
    tmp = max(max(P,Q),max(R,S)) - min(min(P,Q),min(R,S));
    ans = min(ans, tmp);
    if (r == i+1)
      r++;
  }
  print(ans);
  return 0;
}
