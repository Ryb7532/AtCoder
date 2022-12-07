#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,M;
  cin >> N >> M;
  vec<int> A(M),B(M);
  rep(i,M) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  int K;
  cin >> K;
  vec<int> C(K),D(K);
  rep(i,K) {
    cin >> C[i] >> D[i];
    C[i]--; D[i]--;
  }
  int res = 0;
  rep(i,(1<<K)) {
    vec<int> ball(N, 0);
    rep(j,K) {
      if (i&(1<<j)) {
        ball[C[j]]++;
      } else {
        ball[D[j]]++;
      }
    }
    int cnt = 0;
    rep(j,M) {
      if (ball[A[j]]>0 && ball[B[j]]>0)
        cnt++;
    }
    res = max(res,cnt);
  }
  print(res);
  return 0;
}
