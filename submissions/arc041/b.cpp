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
  int N,M;
  cin >> N >> M;
  int B[N][M];
  rep(i,N) {
    string S;
    cin >> S;
    rep(j,M) {
      B[i][j] = S[j]-'0';
    }
  }
  int A[N][M];
  rep(i,N) {
    A[i][0] = A[i][M-1] = 0;
  }
  rep(i,M) {
    A[0][i] = A[N-1][i] = 0;
  }
  rep1(i,N-2) {
    rep1(j,M-2) {
      int tmp = B[i-1][j];
      A[i][j] = tmp;
      B[i-1][j] -= tmp;
      B[i+1][j] -= tmp;
      B[i][j-1] -= tmp;
      B[i][j+1] -= tmp;
    }
  }
  rep(i,N) {
    rep(j,M) {
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}
