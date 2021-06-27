#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  int C[N], A[N][M];
  for (int i=0; i<N; i++) {
    cin >> C[i];
    for (int j=0; j<M; j++)
      cin >> A[i][j];
  }
  int ans = 10000000;
  for (int i = 0; i<(1<<N); i++) {
    int tmp = 0, a[12] = {};
    for (int j=0; j<N; j++) {
      if (i&(1<<j)) {
        tmp += C[j];
        for (int k=0; k<M; k++)
          a[k] += A[j][k];
      }
    }
    bool c = true;
    for (int j=0; j<M; j++)
      if (a[j]<X)
        c = false;
    if (c)
      ans = min(ans, tmp);
  }
  if (ans == 10000000)
    ans = -1;
  cout << ans << endl;
  return 0;
}
