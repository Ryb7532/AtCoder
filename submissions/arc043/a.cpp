#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N; ld A, B;
  cin >> N >> A >> B;
  ld S[N], sum=0, m=1e9, M=0;
  rep(i,N) {
    cin >> S[i];
    sum += S[i];
    m = min(m,S[i]);
    M = max(M,S[i]);
  }
  ld P,Q;
  if (M==m && B!=0) {
    print(-1);
    return 0;
  } else if (M!=m) {
    P = B/(M-m);
  } else {
    P = 0;
  }
  sum *= P;
  Q = A-sum/N;
  printf("%.8Lf %.8Lf\n",P,Q);
  return 0;
}
